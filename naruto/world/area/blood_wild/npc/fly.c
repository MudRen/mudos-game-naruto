#include <npc.h>
#include <ansi.h>

void create()
{
    if( random(100) > 5 ) {
        set_name(HIK"�p����"NOR, ({ "little coal fly", "fly" }) );
        set_level(10);
        set("long", "�p�P���V��j�p���Ҥ��]���A�֦��@�ｿ���ͻH�o�Q�٬��ǡC\n");
        set("set_drop", ({ ([ "type":"obj", "id":122, "amount":1+random(2), "p1":60, "p2":100 ]), }) );
    } else {
        set_name(HIK"���ҽ�"NOR, ({ "fly coal bat", "bat", "fly" }) );
        set_level(55);
        set("long", "�p���Ǫ��i�ƫ��A�ͻH�����j�Ʀ��@�泌�l�A���p�j�N���l���s�C\n");
        set("set_drop", ({ ([ "type":"obj", "id":122, "amount":5+random(15), "p1":100, "p2":100 ]), }) );
    }
    set_race("beast");
    set("age", 100+random(5000));
    set("limbs", ({ "�Y��", "Ĳ��", "�ͻH", "�Ӹ}", "�l��", "����" }) );
    set("chat_chance", 30);
    set("chat_msg", ({
        (: random_move :)
    }));
    setup();
    add_temp("apply/hp", query_level()*10);
    add_temp("apply/evade", query_level()*3);
    do_heal();
}
void die()
{
    object enemy;
    int i;
    enemy = this_object()->last_damage_giver();
    if( !enemy ) {
        ::die();
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            ::die();
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            ::die();
            return;
        }
    }
    i = query_level()*5 - random(query_level());
    if( enemy->query_point("learn") > 1000000 ) {
        i = i*-2;
        tell_object(enemy,HIR"\n�]������"NOR+this_object()->query("name")+HIR"�A�Q�����F"HIY"["HIK+chinese_number(i)+HIY"]"HIR"�I���I�C\n\n"NOR);
    } else {
        tell_object(enemy,"\n�]������"NOR+this_object()->query("name")+"�A�B�~��o�F"HIM"["HIC+chinese_number(i)+HIM"]"NOR"�I���I�C\n\n"NOR);
    }
    enemy->add_point("learn", i);
    ::die();
    return;
}
