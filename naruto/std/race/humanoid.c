/*  humanoid.c - standard race daemon of humanoid type

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#define BASE_WEIGHT 60000

#include <ansi.h>
#include <statistic.h>
#include <combat.h>

inherit F_DBASE;

string* wear_type = ({
    "armor", "cloth", "pants", "face_eq", "feet_eq", "finger_eq",
    "hand_eq", "head_eq", "leg_eq", "neck_eq", "waist_eq", "wrist_eq"
});

void create()
{
    seteuid(getuid());

    set("life_form", "living");
    set("unit", "位");
    set("gender", "male");

    set("default_body", USER_OB);

    set("humanoid", 1);

    set("attitude", "peaceful");            // 心態 default attitude

    set("phase", PHASE_PHYSICAL);	    //設定防禦方式 /feature/char/combat.c defend()

}

void setup(object ob)
{
    seteuid(getuid());

    ob->set_default_object(__FILE__);

    ob->init_attribute();
    ob->init_statistic();
}

// initialize()
//
// To initialize race-specific stuff of a character. 

void initialize(object ob)
{
    ob->set_default_object(__FILE__);
}

/*
string query_appearance(object ob)
{
    mapping attr;
    string a, best_a;
    int num;

    if( !mapp(attr = ob->query_attribute()) ) return "";

    best_a = "int";
    foreach(a, num in attr) if( num > attr[best_a] ) best_a = a;

    switch(best_a) {
        case "str": if( ob->query("gender") == "male") return "長得虎背熊腰，看起來相當孔武有力";
        case "con": if( ob->query("gender") == "male") return "的身形勻稱，看起來體格相當不錯";
    	case "int": if( ob->query("gender") == "male") return "看起來十分機伶，想必聰穎過人";
	case "dex": if( ob->query("gender") == "male") return "生得猿臂狼腰，身手定然十分矯捷";
    }
    
    return "";
}
*/
// valid_wield()
//
// This function determines if a character of this race can wield a
// weapon in certain skill. When a character attempts to wield a weapon,
// the valid_wield() is called in his race daemon and class daemon to
// determine if he can wield it. In this example, we check that a human
// can only wield a primary weapon and a secondhand weapon.

int valid_wield(object me, object ob, string skill)
{
    mapping weapon;
    string *sk;
    int str, best_str;

    // Check strength
    str = me->query_attr("str");
    if( skill[0..8]=="twohanded" ) best_str = ob->weight() / 1000;
    else if( skill[0..7]=="lefthand" ) best_str = ob->weight() / 500;
    else best_str = ob->weight() / 750;

    weapon = me->query_temp("weapon");
    if( !mapp(weapon) || !sizeof(sk = keys(weapon)) ) return 1;

    if( sizeof(sk) >= 2 )
		return notify_fail("你的雙手都沒有空可以裝備這個武器。\n");
    if( skill[0..8] == "twohanded" )
		return notify_fail("裝備" + ob->name() + "需要雙手。\n");
    if( sizeof(sk)==1 ) {
		if( sk[0][0..8] == "twohanded" )
	    	return notify_fail("你已經在使用需要雙手的武器。\n");
		if( sk[0][0..8] != "lefthand" && skill[0..8] != "lefthand" )
	    	return notify_fail("你要裝備兩把以上的武器必須為一右手一左手。\n");
		if( me->query_temp("armor/shield") )    
			return notify_fail("你的雙手都沒有空可以裝備這個武器。\n");
    }
        
    if( str - best_str > 10 )
		write("這" + ob->query("unit") + ob->name() + "拿在手裡輕飄飄的，不是十分趁手。\n");
    else if( str - best_str > 5 )
		write("這" + ob->query("unit") + ob->name() + "對你來說有些輕了，使動起來覺得不怎麼實在。\n");
    else if( str - best_str > -1 )
		write("這" + ob->query("unit") + ob->name() + "的重量對你來說剛剛好，相當趁手。\n");
    else if( str - best_str > -2 )
		write("這" + ob->query("unit") + ob->name() + "的份量重了點，不過你勉強使得動。\n");
    else if( userp(me) )
		return notify_fail("這" + ob->query("unit") + ob->name() + "對你來說太重了，你根本揮不動這麼沉重的兵刃。\n");

    return 1;
}

// valid_wear()
//
// This function determines if a character can wear an armor on certain
// body part. You shuold check if the character of this race DO HAVE that
// body part and didn't wear another armor on the same body part.

int valid_wear(object me, object ob, string part)
{
    if( me->query_temp("armor/" + part) ) return notify_fail("你已經穿戴同類的護具了。\n");
    if( member_array(part, wear_type) == -1 ) return notify_fail("你不能穿戴這一種護具。\n");
    return 1;
}

// statistic_destroyed()
//
// This function is called when the character of this race is physically
// damaged in any of his statistics. The most representive example is to
// check if the character is about to die.

int statistic_destroyed(object ob, mapping flag)
{
    if( flag["hp"] ) ob->heal_stat("hp", ob->query_attr("con"));
    if( flag["ap"] ) ob->heal_stat("ap", ob->query_attr("dex"));
    if( flag["mp"] ) ob->heal_stat("mp", ob->query_attr("int"));
// 不要有暈倒
//    if( flag["hp"] || flag["ap"] || flag["mp"] ) ob->unconcious();
    return 1;
}

// statistic_exhausted()
//
// This function is called when the character of this race has exhausted
// any of his statistics. The most representive example is to check if the
// character is about to fall unconcious.

int statistic_exhausted(object ob, mapping flag)
{
    object killer,ob1;

    killer = ob->last_damage_giver();
    if( ! killer ) killer = ob;

    // Dying
    // Note: this should be checked first bcz character often fall unconcious
    // and die at the same heart beat.

    /* 無HP時 */
    if( flag["hp"] ) {

        ob->die();

        // 物件 ob 有可能在執行完die()後已經不存在了
        if( !ob || !objectp(ob) ) return 1;

        if( !userp(ob) ) {
            destruct(ob);
            return 1;
        }
        log_file("PLAYER_DIE", sprintf("[%s] %s killed by %s\n", ctime(time()), ob->short(1), killer->short(1)));
    }
    
    /* 無AP,MP時 */
//    if( flag["ap"] || flag["mp"] ) {
// 不要有昏倒
//        ob->unconcious();
//        ob->supplement_stat("ap", ob->query_attr("dex"));
//        ob->supplement_stat("mp", ob->query_attr("int"));
//        ob->heal_stat("ap", ob->query_attr("dex"));
//        ob->heal_stat("mp", ob->query_attr("int"));
//    }

    return sizeof(flag)==0;
}
