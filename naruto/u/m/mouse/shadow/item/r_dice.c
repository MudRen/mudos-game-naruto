inherit ITEM;
#include <ansi.h>

int i;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
string report_statusa(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}

void create()
{
    set_name(HIW"���I��l"NOR, ({ "dice"}));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long","�i�H�� roll �Y��l�A���L�|�o�ͤ���ƩO...\n");
    }
    setup();
}
void init()
{
        add_action("do_roll", ({ "roll", "throw" }));
}
int do_roll(string arg)
{
    object me;
    me = this_player();
    if( !id(arg) ) return 0;
    if( me->query_temp("quest/rolldice") == 1) {
    return notify_fail(CYN"�w�g�b�ϥΤ��F�C"NOR"\n");
    }
    if( this_player()->is_busy()) {
        write(CYN"���L���A�S�ť��l�C"NOR"\n");
        return 1;
    }
    if( !this_player()->is_fighting() ) {
        write(CYN"�S���԰����i�ϥέ��I��l�C"NOR"\n");
        return 1;
    }
    i = random(101);
    me->add_temp("quest/rolldice", 1);
    if( i >= 95) {
        message_vision("$N���X��l�@�Y�A��l�u�F�u���U�ӡA���G�O"YEL"�j�N"NOR"�I\n", me);
        call_out("risks_1",5,me);
        return 1;
    } else
    if( i < 95 && i >= 81) {
        message_vision("$N���X��l�@�Y�A��l�u�F�u���U�ӡA���G�O"HIY"�N"NOR"�I\n", me);
        call_out("risks_1",5,me);
        return 1;
    } else
    if( i < 81 && i >= 61) {
        message_vision("$N���X��l�@�Y�A��l�u�F�u���U�ӡA���G�O"HIW"�p�N"NOR"�I\n", me);
        call_out("risks_1",5,me);
        return 1;
    } else
    if( i < 61 && i >= 40) {
        message_vision("$N���X��l�@�Y�A��l�u�F�u���U�ӡA���G�O"WHT"��"NOR"�I\n", me);
        message_vision(HIW"�u���u�y�I�v�a�@�}����«�_�A���S�o�ͥ���Ʊ��C\n"NOR, me);
        me->delete_temp("quest/rolldice");
        destruct(this_object());
        return 1;
    } else
    if( i < 40 && i >= 20) {
        message_vision("$N���X��l�@�Y�A��l�u�F�u���U�ӡA���G�O"HIM"�p��"NOR"�I\n", me);
        call_out("risks_1",5,me);
        return 1;
    } else
    if( i < 20 && i >= 6) {
        message_vision("$N���X��l�@�Y�A��l�u�F�u���U�ӡA���G�O"HIR"��"NOR"�I\n", me);
        call_out("risks_1",5,me);
        return 1;
    } else
    if( i < 6) {
        message_vision("$N���X��l�@�Y�A��l�u�F�u���U�ӡA���G�O"RED"�j��"NOR"�I\n", me);
        message_vision(HIR"�u�I�I�v�a�@�n�A�@��"HIK"����"HIR"�̪ťX�{�A�H�⮳�_�I�M��$N�@�A�I\n"NOR, me);
        me->delete_temp("quest/rolldice");
        me->unconcious();
        destruct(this_object());
        return 1;
    }
    return 1;
}
void risks_1()
{
    int damage;
    object enemy, me;
    me = this_player();
    enemy = me->query_opponent();
    me->delete_temp("quest/rolldice");
    if( i < 40 && i >= 20) {
        message_vision("�u���@�}�������X�{"HIK"����"NOR"�����v�A��$N�ΤO�@���I\n", me);
        damage = me->query_ability("attack");
        me->damage_stat("hp", damage, me);
        message_vision("        $N�u��I�v�a�@�n�A���W�Q���X�ƨ�岪�I("+damage+")"+report_statusa(me)+"", me);
        destruct(this_object());
        return;
    } else
    if( i < 20 && i >= 6) {
        message_vision("�u���@�}�������X�{"HIR"�]�s"NOR"�����v�A��$N�ΤO�@���I\n"NOR, me, enemy);
        damage = me->query_ability("attack")*3;
        me->damage_stat("hp", damage, me);
        message_vision("        $N�ݫe�A��g�Q�A�V�᭸�^�F�X�h�I("+damage+")"+report_statusa(me)+"", me);
        destruct(this_object());
        return;
    }
    if( !enemy ) {
        destruct(this_object());
        return;
    }
    // �ĤH�b���P��m
    if( environment(me)->is_area() ) {
        if( !area_environment(me, enemy) ) {
            destruct(this_object());
            return;
        }
    } else {
        if( environment(enemy) != environment(me) ) {
            destruct(this_object());
            return;
        }
    }
    if( i >= 95) {
        message_vision("�u���@�}�������X�{"HIG"�էU"NOR"�����v�A��$N�o�X"HIC"�F�Y"NOR"�I\n", enemy);
        damage = me->query_ability("attack")*5;
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�Q"HIC"�F�Y"NOR"�F�Ӧѻ��A���F���˯����_�ӡI("+damage+")"+report_status(enemy)+"", me, enemy);
        destruct(this_object());
        return;
    } else
    if( i < 95 && i >= 81) {
        message_vision("�u���@�}�������X�{"HIW"���"NOR"�����v�A�ޥX"YEL"�F�C"NOR"��$N�ΤO�@�A�I\n", enemy);
        damage = me->query_ability("attack")*2;
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�Q���X�@�D�f�l�A�A�媽�y�I("+damage+")"+report_status(enemy)+"", me, enemy);
        destruct(this_object());
        return;
    } else
    if( i < 81 && i >= 60) {
        message_vision("�u���@�}�������X�{$N�����v�A��$n�ΤO�@���I\n", me, enemy);
        damage = me->query_ability("attack");
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        $n�Q�@�������h�F�X�B�A�L���y�X�A��I("+damage+")"+report_status(enemy)+"", me, enemy);
        destruct(this_object());
        return;
    }
    return notify_fail("�ϥΥ��ѡC\n");
}
