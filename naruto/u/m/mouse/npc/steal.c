#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void do_fight()
{
    int bank;
    object enemy;
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    bank = random(999) + 601;
    message_vision("$N"HIY"���X�@�x��b���A���F"NOR"$n"HIY"���H�Υd�g�ꤣ���I\n"NOR, this_object(), enemy);
    if( enemy->query("bank") <= 1000 ) {
        message_vision("$N�H�H��ۡR"HIG"$n"NOR+HIG"�u�a��...�٨S��N�z��F�C\n"NOR, this_object(), enemy);
        return;
    }
    message_vision(HIG"�Ȧ�q��$n�Q����("HIY+bank+HIG")��Ȥl�I\n"NOR, this_object(), enemy);
    enemy->add("bank", -bank);
    this_object()->add("bank", bank);
    return;
}
void do_money()
{
    int i;
    i = random(200) - 100;
    if( this_object()->query("bank") > 5000 && (this_object()->query_stat_current("hp") < this_object()->query_stat_maximum("hp")*0.5) ) {
        message_vision("$N�j�۵ۡG"HIG"�ڦ����F�I�֨��������ˡI\n"NOR, this_object());
        message_vision(HIW"��M"HIW""BLK"����³ǧJ"HIW"�X�{�b�o�̡A�έ��֪���N�v�n�F"NOR"$N"HIW"���W���˵h�C\n"NOR, this_object());
        this_object()->heal_stat("hp", 9999);
        this_object()->add("bank", -5000);
        return;
    } else if( this_object()->query_stat_current("hp") < this_object()->query_stat_maximum("hp")*0.3 ) {
        message_vision("$N�h�W���۵ۡG"HIG"���֯�ϱϧڪ��I\n"NOR, this_object());
        return;
    }
    message_vision(CYN"$N�f�����ۻy�����D�b������C\n"NOR, this_object());
    return;
}
void create()
{
    set_name("�T�]���l", ({ "Steal Child", "child" }));
    set("nickname",HIR"�^�ѧT�]"NOR);
    set("title",HIK"�S���m��"NOR);
    set_race("human");
    set_level(15+random(5));
    set("age", 10);
    set("long", "�����}�}���ꪺ�A�@���n�ۧA�����]�r�ݡC\n");
    set("guard_exit", ({ 
        "west", "east", "north", "south", "up", "down",
        "northeast", "northwest", "southeast", "southwest"
    }));
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command, "coco" :),
        (: do_fight :),
        (: do_money :),
    }) );
    setup();
}
int do_guard_exit(int x, int y, string exit)
{
    message_vision("$N���X�}��$n�̭˦b�a�W�C\n", this_object(), this_player());
    do_chat(({ 
       NOR"�T�]���l���D�R"HIG"���ٳh�W��H�H���h��\n"NOR,
       NOR"�T�]���l���D�R"HIG"�����X����S���٬O�n�X����\n"NOR,
    }));
    return 1;
}
void die()
{
    int bank;
    object enemy;
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
    message_vision("$N�j�s�ۡR"HIG"���F�]�n�a$n�����U�h�����I\n"NOR, this_object(), enemy);
    if( enemy->query("bank") <= 10000 ) {
        message_vision("$N�γ̫�@�f�𻡡R"HIG"�~�M�S���i�H���I...�ӥ��Ѱա�\n"NOR, this_object(), enemy);
        ::die();
        return;
    }
    message_vision(HIG"�Ȧ�q��$n�Q����("HIY"10000"HIG")��Ȥl�I\n"NOR, this_object(), enemy);
    enemy->add("bank", -10000);
    ::die();
    return;
}
