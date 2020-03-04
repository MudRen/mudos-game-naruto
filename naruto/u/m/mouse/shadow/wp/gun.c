#include <weapon.h>
#include <ansi.h>

inherit F_WEAPON;
int i;
int j;
int k;
int l;
int m;
int do_rifle(object obj);
int do_fire(object obj);
int do_attack(object obj);
int do_gin(object obj);
int do_die(object obj);

string *atk_msg = ({
        "����", "�k��", "���u", "�k�u", "���L", "�k�L", "����", "�k��",
        "����", "�k��", "����", "�k��", "���}", "�k�}", "�{�l", "�I��",
});

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}

string *combat_wp = ({
    "$N���|$w�e�W�j���u"HIY+BLINK"���γt�g"NOR"�v�l�u�f�f�f�a�ƨg�g�V$n",
    "$N�N$w�j�f�ˤW�h�u�˸m�A���$n�Ҧb��m�o�g�h�u����",
    "$N��j�I�b����A���X��h�u�@�r�A�ֳt��V$n",
    "$N���}$w���Ů𦬯Ǿ��u"HIW"�Ů�"NOR"�v�I�a�@�n�g�V$n",
    "$N���X���v�o�g���˦b$w�W�A�uť���m�m���n�A�L�ƿ��v�w��$n���h",
    "$N�N$w���|�L���A�a�W����ªŮg���A�u���Ť��@�}�{���A�ƪT�l���u�g�V$n",
});

string getCombatAction(object me, object weapon)
{
    if( weapon->is_weapon() ) return combat_wp[random(sizeof(combat_wp))];
    else return RACE_D(me->query_race())->query_action();
}

void create()
{
    set_name(HIK"�h�\\��"HIR"�B�j"NOR, ({ "diversify rifle", "rifle", "gun" }));
    set_weight(5000);
    setup_weapon(1, 1, 1, 1);
    
    if( !clonep() ) {
        set("wield_as", ({ "twohanded" }) );
        set("unit", "��");
        set("value", 101);
        set("have_mag", 1);
        set("long", @LONG
�Ӧۥ~�P�������Z���A�@��j�]�t�F�h�غj���\��A�¤O�j�j�C
�ثe��ϥΪ��Z���������G
����������������������������������������������������������
�x�j  �آx�� �� �O�x�`�u�Ƣx��  ��  ��  �k              �x
����������������������������������������������������������
�x�Ӻֺj�x20-200  �x50(1) �xfiregun rifle on mob        �x
�x���b���x500     �x5(1)  �xfiregun fire on mob         �x
�x�����j�x10-60*5 �x200(5)�xfiregun attack on mob       �x
�x�믫�i�x10-100  �x10(1) �xfiregun gin on mob          �x
�x�����i�x?       �x500(?)�xfiregun die on mob          �x
�x      �x        �x      �x                            �x
�x      �x        �x      �x                            �x
�x      �x        �x      �x                            �x
����������������������������������������������������������
�x�d  �ߢx0       �x��    �xcheck gun                   �x
����������������������������������������������������������
�x��  �u�x0       �x��    �xchange gun                  �x
����������������������������������������������������������
LONG);
    }
    set("wield_msg", "�|�P�ǥX"RED"����u�@��ĵ�١v"NOR"ĵ���n�A$N���W���X$n�ˤW�u���H�ɷǳƧ����I\n");
    set("unwield_msg", "��O���^��"HIG"���u�w��ĵ�١v"NOR"�ɡA$N���w�N$n�æ^���W�C\n");
    setup();
}
void init()
{
    add_action("do_firegun", "firegun");
    add_action("do_change", "change");
    add_action("do_check", "check");
}
int do_change(string arg)
{
    if( this_player()->is_busy()) {
        write(CYN"�A���b���L�A�S�Ŵ��u�C"NOR"\n");
        return 1;
    }
    if( this_player()->is_fighting() ) {
        write(CYN"�԰����S�Ŵ��u�աC"NOR"\n");
        return 1;
    }
    if( arg == "gun" ) {
        message_vision("$N���_"HIK"�h�\\��"HIR"�B�j"NOR"�}�l�󴫼u���C\n"NOR, this_player());
        if( i >= 40) {
            this_player()->start_busy(1);
            i = 0;
            write("�������R"HIG"�Ӻֺj�u�ܧ󴫧����C"NOR"\n");
            return 1;
        }
        if( j >= 4) {
            this_player()->start_busy(1);
            j = 0;
            write("�������R"HIG"���b�����u�ɥR�����C"NOR"\n");
            return 1;
        }
        if( k >= 80) {
            this_player()->start_busy(1);
            k = 0;
            write("�������R"HIG"���j�u���ɥR�����C"NOR"\n");
            return 1;
        }
        if( l >= 5) {
            this_player()->start_busy(1);
            l = 0;
            write("�������R"HIG"�믫�෽�ɥR�����C"NOR"\n");
            return 1;
        }
        if( m >= 400) {
            this_player()->start_busy(1);
            m = 0;
            write("�������R"HIG"�����i�ʸɥR�����C"NOR"\n");
            return 1;
        }
        write("�������R"HIG"�u�ƤQ���R���A���Χ󴫡C"NOR"\n");
        return 1;
    }
}
int do_check(string arg)
{
    int a;

    if( arg == "gun" ) {
        message_vision(CYN"$N�J���ˬd�۳Ѿl�u�ơC\n"NOR, this_player());
        a = 50;
        a = a - i;
        write("�������R"HIG"�Ӻֺj�l�u�Ѿl("HIY+a+HIG")�o�C"NOR"\n");
        a = 5;
        a = a - j;
        write("�������R"HIG"���b�����u�Ѿl("HIR+a+HIG")�o�C"NOR"\n");
        a = 200;
        a = a - k;
        write("�������R"HIG"���j�u���Ѿl("HIB+a+HIG")�o�C"NOR"\n");
        a = 10;
        a = a - l;
        write("�������R"HIG"�믫���u�෽�Ѿl("NOR+GRN+a+HIG")�C"NOR"\n");
        a = 500;
        a = a - m;
        write("�������R"HIG"�����i�ʳѾl("HIK+a+HIG")�C"NOR"\n");
        return 1;
    }
}
int do_firegun(string arg)
{
    string func,target;
    object ob;

    if( this_player()->is_busy()) {
        write(CYN"�A���b���L���A�S�ťκj�C"NOR"\n");
        return 1;
    }
    if( !this_object()->query("equipped")) {
        write("�������R"HIG"�A�S���j���ΡC"NOR"\n");
        return 1;
    }
    if( !this_player()->is_fighting() ) {
        write("�������R"HIG"�A�S�b�԰��A����κj�C"NOR"\n");
        return 1;
    }
    if ( !arg || sscanf(arg, "%s on %s", func, target)!=2 )
           return notify_fail("�������R"HIG"�A�Q�g�֪��H"NOR"\n");

    if ( !objectp(ob = present(target, environment(this_player()))) )
            return notify_fail("�������R"HIG"�A�Q�g�֪��H"NOR"\n");

    if ( !ob ||
         !ob->is_character() ||
         ob->is_corpse() ||
         ob==this_player() )
         return notify_fail("�������R"HIG"�A�Q�g�֪��H\n"NOR);

    if( func == "rifle") {  do_rifle(ob); }
    if( func == "fire") {  do_fire(ob); }
    if( func == "attack") {  do_attack(ob); }
    if( func == "gin") {  do_gin(ob); }
    if( func == "die") {  do_die(ob); }
    return 1;
}
int do_rifle(object ob)
{
    string msg;
    object me;
    int damage;

    me = this_player();
    msg = atk_msg[random(sizeof(atk_msg))];

    message_vision("$N���D�R"HIG"�Ӻֺj�Ҧ��C\n"NOR, me, ob);
    if( i < 50) {
        message_vision("$N�⤤�Z���C�C�ܤƦ�"HIY"�Ӻֺj"NOR"���ˤl�A���$n�@�j�F�h�I\n", me, ob);
        i = i+1;
        damage = random(181) + 20;
        if( random(me->query_ability("evade")) - random(ob->query_ability("evade"))) {
            ob->damage_stat("hp", damage, ob);
            message_vision("        $n�Q�l�u����"+msg+"�I�h���z�z�j�s�C("+damage+")"+report_status(ob)+"", me, ob);
            me->start_busy(1);
            return 1;
        }
        message_vision("        $n���N�]���������A���O�@�o�l�u(0)"+report_status(ob)+"", me, ob);
        me->start_busy(2);
        return 1;
    }
    message_vision("�������R"HIG"���i�A�l�u�w�g�Χ��C\n"NOR, me, ob);
    me->start_busy(1);
    return 1;
}
int do_fire(object ob)
{
    object me;
    int damage;

    me = this_player();

    message_vision("$N�b�۵ۻ��D�R"HIG"���b���Ҧ��C\n"NOR, me, ob);
    if( j < 5) {
        message_vision("$N�⤤�Z����˦�"HIR"���b��"NOR"���ˤl�A�u�F�I�v�a�@�n�o�g�I\n", me, ob);
        j = j+1;
        damage = 500;
        if( random(ob->query_ability("defend")) < random(501)) {
            ob->damage_stat("hp", damage, ob);
            message_vision("        �u�F���v����«�_�A�J�¦p����$n�N���b�������U��C("+damage+")"+report_status(ob)+"", me, ob);
            me->start_busy(2);
            ob->start_busy(1);
            return 1;
        }
        message_vision("        �u�F���v����«�_�A$n���F���W���I�J�¨õL�jê�C(0)"+report_status(ob)+"", me, ob);
        me->start_busy(4);
        return 1;
    }
    message_vision("�������R"HIG"���i�A���u�w�g�Χ��C\n"NOR, me, ob);
    me->start_busy(2);
    return 1;
}
int do_attack(object ob)
{
    string msg;
    object me;
    int damage;

    me = this_player();

    message_vision("$N���D�R"HIG"�����j�Ҧ��C\n"NOR, me);
    if( k > 200) {
        k = 200;
    }
    if( k < 200) {
        message_vision("$N�⤤�Z����˦�"HIB"�����j"NOR"�u��.��.��..�I�v�s��g���I\n", me);
        if((80 - random(ob->query_ability("wittiness"))) < 0) {
            k = k + 5;
            message_vision("���O$n���G�S�����ˡC(0)"+report_status(ob)+"", me, ob);
            me->start_busy(1);
            if( random(5) < 2) {
                message_vision(CYN"$N�����ߨ谱��g���I\n"NOR, me, ob);
                return 1;
            }
        } else {
            damage = 10 + random(51);
            msg = atk_msg[random(sizeof(atk_msg))];
            ob->damage_stat("hp", damage, ob);
            k = k + 5;
            message_vision("$n�Q�j�l���l�u�e��"+msg+"�I("+damage+")"+report_status(ob)+"", me, ob);
        }
        if((80 - random(ob->query_ability("wittiness"))) < 0) {
            k = k + 5;
            message_vision("���O$n���G�S�����ˡC(0)"+report_status(ob)+"", me, ob);
            me->start_busy(1);
            if( random(5) < 2) {
                message_vision(CYN"$N�����ߨ谱��g���I\n"NOR, me, ob);
                return 1;
            }
        } else {
            damage = 10 + random(51);
            msg = atk_msg[random(sizeof(atk_msg))];
            ob->damage_stat("hp", damage, ob);
            k = k + 5;
            message_vision("$n�Q�j�l���l�u�e��"+msg+"�I("+damage+")"+report_status(ob)+"", me, ob);
        }
        if((80 - random(ob->query_ability("wittiness"))) < 0) {
            k = k + 5;
            message_vision("���O$n���G�S�����ˡC(0)"+report_status(ob)+"", me, ob);
            me->start_busy(1);
            if( random(5) < 2) {
                message_vision(CYN"$N�����ߨ谱��g���I\n"NOR, me, ob);
                return 1;
            }
        } else {
            damage = 10 + random(51);
            msg = atk_msg[random(sizeof(atk_msg))];
            ob->damage_stat("hp", damage, ob);
            k = k + 5;
            message_vision("$n�Q�j�l���l�u�e��"+msg+"�I("+damage+")"+report_status(ob)+"", me, ob);
        }
        if((80 - random(ob->query_ability("wittiness"))) < 0) {
            k = k + 5;
            message_vision("���O$n���G�S�����ˡC(0)"+report_status(ob)+"", me, ob);
            me->start_busy(1);
            if( random(5) < 2) {
                message_vision(CYN"$N�����ߨ谱��g���I\n"NOR, me, ob);
                return 1;
            }
        } else {
            damage = 10 + random(51);
            msg = atk_msg[random(sizeof(atk_msg))];
            ob->damage_stat("hp", damage, ob);
            k = k + 5;
            message_vision("$n�Q�j�l���l�u�e��"+msg+"�I("+damage+")"+report_status(ob)+"", me, ob);
        }
        if((80 - random(ob->query_ability("wittiness"))) < 0) {
            k = k + 5;
            message_vision("���O$n���G�S�����ˡC(0)"+report_status(ob)+"", me, ob);
            me->start_busy(1);
            if( random(5) < 2) {
                message_vision(CYN"$N�����ߨ谱��g���I\n"NOR, me, ob);
                return 1;
            }
        } else {
            damage = 10 + random(51);
            msg = atk_msg[random(sizeof(atk_msg))];
            ob->damage_stat("hp", damage, ob);
            k = k + 5;
            message_vision("$n�Q�j�l���l�u�e��"+msg+"�I("+damage+")"+report_status(ob)+"", me, ob);
        }
        message_vision(CYN"$N����F�s����j�g���I\n"NOR, me, ob);
        return 1;
    }
    message_vision("�������R"HIG"���i�A���j�u���w�g�Χ��C\n", me);
    return 1;
}
int do_gin(object ob)
{
    object me;
    int damage;

    me = this_player();

    message_vision("$N���D�R"HIG"�믫���u�C\n"NOR, me, ob);
    if( l < 10) {
        message_vision("$N�Z�������p�F�o�g�����ˤl�A�o�g�X"GRN"��⪺����"NOR"�I\n", me, ob);
        l = l+1;
        damage = 10+random(91);
        if( random(ob->query_ability("evade")) < random(301)) {
            ob->damage_stat("ap", damage, ob);
            message_vision("        �u�G���v�@�n����g��$n�Y���A$n�uı�o�����@���V�áC("+damage+")"+report_status(ob)+"", me, ob);
            ob->start_busy(2);
            return 1;
        }
        message_vision("        �u�ԡv�a�@�n�A������b�a�W�z�X���@�ߡC(0)"+report_status(ob)+"", me, ob);
        me->start_busy(1);
        return 1;
    }
    message_vision("�������R"HIG"���i�A�෽�w�g�κɡC\n"NOR, me, ob);
    me->start_busy(2);
    return 1;
}
int do_die(object ob)
{
    string msg;
    int b;
    object me;
    int damage;

    me = this_player();
    b = ob->query_stat("hp");
    msg = atk_msg[random(sizeof(atk_msg))];

    message_vision("$N���D�R"HIG"�����C\n"NOR, me, ob);
    if( m < 500) {
        message_vision("$N�Z�������׹p�w���ˤl�A�o�g�X"HIK"�¦⦺���i"NOR"�I\n", me, ob);
        if( b > 500) {
            b = 500;
        }
        m = m+b;
        if( m > 500) {
            b = m - 500;
            m = 500;
        }
        damage = b+1;
        if( random(50) > 20) {
            ob->damage_stat("hp", damage, ob);
            message_vision("        �¥�����$n"+msg+"�A$n�Pı������O�ֳt�y���I("+damage+")"+report_status(ob)+"", me, ob);
            ob->start_busy(2);
            return 1;
        }
        message_vision("        ���G�¥���������A�����g���F�C(0)"+report_status(ob)+"", me, ob);
        me->start_busy(1);
        return 1;
    }
    message_vision("�������R"HIG"���i�A�෽�w�g�κɡC\n"NOR, me, ob);
    me->start_busy(2);
    return 1;
}
