/* consider.c */

inherit F_CLEAN_UP;

string consider(int ability)
{
	if( ability < -150 ) return "遠勝於你";
	if( ability < -80 ) return "高出你甚多";
	if( ability < -40 ) return "高出你一截";
	if( ability < -10 ) return "比你略勝一籌";
	if( ability < 10 ) return "與你只在伯仲之間";
	if( ability < 40 ) return "略遜你一籌";
	if( ability < 80 ) return "和你相比相差一截";
	if( ability < 150 ) return "和你相比頗為不如";
	return "遠遜於你";
}

int main(object me, string arg)
{
    object ob, weapon;
	int me_ability, ob_ability;
    mapping wielded_weapon;
    string msg, sk, art, skill;

	if( !arg ) return notify_fail("你想評估誰的實力？\n");
	
	ob = present(arg, environment(me));
	if( !ob || !ob->is_character() || !ob->visible(me) )
	    return notify_fail("這裡沒有 " + arg + " 這個人。\n");

    msg = "你評估" + ob->query("name") + "的實力：\n";
    
    // 攻擊力量
    me_ability = 0;
    wielded_weapon = me->query_temp("weapon");
    if( mapp(wielded_weapon) && sizeof(wielded_weapon) ) {
        foreach(skill, weapon in wielded_weapon) {
            art = me->skill_mapped("combat");
            if( ! art ) continue;
            me_ability += weapon->show_damage();
        }
    } else me_ability = me->show_damage();

    ob_ability = 0;
    wielded_weapon = ob->query_temp("weapon");
    if( mapp(wielded_weapon) && sizeof(wielded_weapon) ) {
        foreach(skill, weapon in wielded_weapon) {
            art = ob->skill_mapped("combat");
            if( ! art ) continue;
            ob_ability += weapon->show_damage();
        }
    } else ob_ability = ob->show_damage();

    msg += "攻擊力量" + consider(me_ability-ob_ability);

    // 防禦力
    me_ability = me->query_ability("defend");
    if( (sk=me->skill_mapped("parry")) ) me_ability += SKILL_D(sk)->parry_show(me, 0);

    ob_ability = ob->query_ability("defend");
    if( (sk=ob->skill_mapped("parry")) ) ob_ability += SKILL_D(sk)->parry_show(ob, 0);

    msg += "，防禦力量" + consider(me_ability-ob_ability) + "。\n";

    // 攻擊技巧
    me_ability = me->query_ability("intimidate"),
    ob_ability = ob->query_ability("intimidate"),

    msg += "攻擊技巧" + consider(me_ability-ob_ability);

    // 防禦技巧
    me_ability = me->query_ability("wittiness"),
    ob_ability = ob->query_ability("wittiness"),

    msg += "，防禦技巧" + consider(me_ability-ob_ability) + "。\n";

    // 命中率
    me_ability = me->exact();
    ob_ability = ob->exact();

    msg += "命中能力" + consider(me_ability-ob_ability);

    // 迴避率
    me_ability = me->query_ability("evade");
    if( (sk=me->skill_mapped("dodge")) ) me_ability += SKILL_D(sk)->dodge_show(me, 0);

    ob_ability = ob->query_ability("evade");
    if( (sk=ob->skill_mapped("dodge")) ) ob_ability += SKILL_D(sk)->dodge_show(ob, 0);

    msg += "，迴避能力" + consider(me_ability-ob_ability) + "。\n";

    write(msg);

    return 1;
}

int help()
{
    write(@TEXT
指令格式：consider 對象

這個指令讓你大略評估一個對手的實力。
TEXT);
    return 1;
}
