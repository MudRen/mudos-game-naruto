#include <ansi.h>
#define SKILL_NAME "lending ticket"
#define SKILL_NAME_C "�ɶU��"
#define SKILL_CLASS "special"

inherit SKILL;

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

void skill_advanced(object me, string skill)
{
    int lv = me->query_skill(skill, 1);
    switch( lv ) {
        case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
        case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
        case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// �B�ԧޯ�G���پ� ���m�� �̰� +armor 100
void do_rain(object me)
{
    mapping cnd = ([]);
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 40 || sk < 40 ) {
        write("�A���S��t�{�׻P�ɶU�鵥�ť����n�b 40 �H�W�C\n");
        return;
    }
    if( me->query_stat("mp") < 100 ) {
        write("�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return;
    }
    if( me->query_condition("waterwall", 1) != 0) {
        write("�A�w�g�Τ��پ��O�@�ۤv�F�C\n");
        return;
    }
    message_vision("\n$N���X�y"CYN"���P"NOR"�z���L������b���ǵe�X�@�ӥ��j����Ρu"HIC"���پ�"NOR"�v\n"NOR, me);

    cnd["name"] = HIC+"���پ�"+NOR;
    cnd["duration"] = sk/2;
    cnd["from"] = me;
    cnd["add"] = sk/2;
    cnd["ability"] = "armor";

    me->set_condition("waterwall", cnd);
    message_vision(HIC"�Ω��O�ҥ�X�Ӫ����W�ֳt�]���"NOR"$N"HIC"�A��"NOR"$N"HIC"�����m��O�����F�C\n\n"NOR, me);

    me->damage_stat("mp", 100, me);
    me->start_busy(3);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

// ���ԧޯ�G�������N �v���ۤv �̰�25%, cd�ɶ�3����
void do_music(object me)
{
    mapping cnd = ([]);
    int sk, heal, cd, hd;

    sk = me->query_skill(SKILL_NAME, 1);
    hd = me->query_stat_maximum("hp")-me->query_stat_current("hp");
    heal = (me->query_stat_maximum("hp")*(sk + me->query_skill("special")))/1600;
 
    if( heal > hd ) {
        cd = 100*hd/me->query_stat_maximum("hp");
        heal = hd;
    }
    else cd = 100;

    if( me->query_skill("special", 1) < 50 || sk < 30 ) {
        write("�A���S��t�{�׵��ť����b 50 �H�W�B�ɶU�鵥�ť����b 30 �H�W�C\n");
        return;
    }
    if( me->query_stat("mp") < 100 ) {
        write("�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return;
    }
    if( me->query_stat("hp") >= me->query_stat_maximum("hp") ) {
        write("�A�S�S�����ˡA�F�¨S�ƹ�ۤv�ɦ�\n");
        return;
    }
    if( me->query_condition("music_heal") ) {
        write("�A�ٵL�k�ϥγo�ۡC\n");
        return;
    }
    message_vision("\n$N�N��K�b�ۤv���ˤf�W�A�}�l�B�_���O"HIM"�u�������N�v"NOR"�u���ˤf�����N�n��F...("HIM+heal+NOR")\n\n"NOR, me);

    cnd["name"] = HIM+"(CD)����"+NOR;
    cnd["duration"] = (cd*(18/10))/2;

    me->set_condition("music_heal", cnd);
    me->heal_stat("hp", heal);
    me->damage_stat("mp", 100, me);
    me->improve_skill(SKILL_NAME, 1);
    me->start_busy(1);
    return;
}

// �q���Q�ޯ�G��M�W��-�����̤j�� �̦h6%
void do_ton(object me, object target)
{
    mapping cnd = ([]);
    int sk, damage, i;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 30 || sk < 50 ) {
        write("�A���S��t�{�׵��ť����b 30 �H�W�B�ɶU�鵥�ť����b 50 �H�W�C\n");
        return;
    }
    if( me->query_stat("mp") < sk/5 ) {
        write("�A���骬�p���ΡA����ҥ�q���Q�����C\n");
        return;
    }
    if( !me->is_fighting(target) ) {
        write("�A����èS���b��Ԥ��C\n");
        return;
    }
    if( me->query_condition("music_heal") ) {
        write("�A�ٵL�k�ϥγo�ۡC\n");
        return;
    }
    message_vision(HIG"$N"HIG"�����q�h�̮��X��M�A�w�w�a�a��"NOR"$n"HIG"...\n"NOR, me, target);

    i = (sk-20)/30;
    damage = target->query_stat_maximum("hp")*i/100;

    // �若��O�̤j�Ȫ� sk ���ӭ���
    if( damage >= i*500 ) damage = i*500;

    if( !COMBAT_D->isHit(me, target) ) {
        message_vision("\t���O$N���U�۪`�N$n�S�ݨ�a�W�����Y�A�L�F�Ӫ��Y�ˡC\n"NOR, me, target);
        me->damage_stat("mp", sk/10, me);
        me->start_busy(2);
        return;
    }
    target->receive_damage(damage, me);
    message_vision( sprintf("\t$N���S�����a��$n���I��ΤO�@��A�u�P�v���@�n�A��|�q(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
    me->damage_stat("mp", sk/10, me);
    me->start_busy(2);

    cnd["name"] = HIW+"(CD)��M"+NOR;
    cnd["duration"] = 20;

    me->set_condition("music_heal", cnd);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

// �j��H�ޯ�G�j��� -- �w�H�p�A�̰�2-4�^
void do_spider(object me, object target)
{
    mapping cnd = ([]);
    int sk, damage;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 60 || sk < 60 ) {
        write("�A���S��t�{�׵��ť����b 60 �H�W�B�ɶU�鵥�ť����b 60 �H�W�C\n");
        return;
    }
    if( me->query_stat("mp") < sk/10 ) {
        write("�A���骬�p���ΡA�S��k���ƻj�ﵷ�C\n");
        return;
    }
    if( !me->is_fighting(target) ) {
        write("�A����èS���b��Ԥ��C\n");
        return;
    }
    if( me->query_condition("music_heal") ) {
        write("�A�ٵL�k�ϥγo�ۡC\n");
        return;
    }
    if( target->is_busy() ) {
        write("���w�g�L�k��ʤF�C\n");
        return;
    }
    message_vision(HIW"$N"HIW"�N��x�¤W�\\�X�@�ӿW�S���ǲ����աA���M�⩹�e�@���Q�X�j�q�յ��I\n"NOR, me, target);
    if( !COMBAT_D->isHit(me, target) ) {
        message_vision("\t���G�յ��S������H�b���񪺦a�W�A�ϦӼv�T�F$N����ʡC\n"NOR, me, target);
        me->damage_stat("mp", sk/10, me);
        me->start_busy(3);
    } else {
        message_vision("\t�u��$n�{�פ���Q�յ��ι��H��ʼu���o����$N�ӮƲz�աI\n"NOR, me, target);
        me->damage_stat("mp", sk/10, me);
        me->start_busy(1);
        target->start_busy(sk/50 - random(2));
    }
    cnd["name"] = HIW+"(CD)�j��"+NOR;
    cnd["duration"] = 8;

    me->set_condition("music_heal", cnd);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

// �\�ڧޯ�G��\ (�ȮɨS�����ȥi�H��)
void do_bow(object me)
{
    mapping cnd = ([]);
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 100 || sk < 80 ) {
        write("�A���S��t�{�׵��ť����b 100 �H�W�B�ɶU�鵥�ť����b 80 �H�W�C\n");
        return;
    }
    if( me->query_stat("mp") < 200 ) {
        write("�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");
        return;
    }
    if( me->query_condition("waterwall", 1) != 0) {
        write("�A�ثe���B��o�l�����A���C\n");
        return;
    }
    message_vision(HIY"\n$N"HIY"�N���O�ഫ����O�A�b��F���M�ɩ��M�j�ܤ@�n�u�ܡI�v"HIR"�y�o�l�z"NOR"\n"NOR, me);

    cnd["name"] = HIR+"�o�l"+NOR;
    cnd["duration"] = sk;
    cnd["from"] = me;
    cnd["add"] = sk/2;
    cnd["ability"] = "attack";

    me->set_condition("waterwall", cnd);
    message_vision("$N�����F�ۨ��������O�q�A�s���_���Y�ɳ��o�X�س��n�T�C\n"NOR, me);

    // �W�[�ޯ�g��
    me->damage_stat("mp", 200, me);
    me->start_busy(3);
    me->improve_skill(SKILL_NAME, 1);
    return;
}

// �˨��ޯ�G�������R (�ȮɨS�����ȥi�H��)
void do_wheya(object me, object target)
{
    int sk, damage, raiseDamage, i;
    object wp;

    sk = me->query_skill(SKILL_NAME, 1);

    if( me->query_skill("special", 1) < 100 || sk < 100 ) {
        write("�A���S��t�{�׵��ť����b 100 �H�W�B�ɶU�鵥�ť����b 100 �H�W�C\n");
        return;
    }
    if( me->query_stat("mp") < sk/4 ) {
        write("�A���骬�p���ΡA�L�k�ϥΦ˨��S�ޡC\n");
        return;
    }
    if( !me->is_fighting(target) ) {
        write("�A����èS���b��Ԥ��C\n");
        return;
    }
    if( me->query_stat("hp") < 500 ) {
        write("�A����O�Ӥ֤F�A�L�k�t��o�өۦ��C\n");
        return;
    }
    me->damage_stat("mp", sk/4, me);
    message_vision(HIR"$N"HIR"Ÿ�ݨ��l�A���M���Y��}���z�}��ӥX"HIY"�y"NOR+RED+BLINK"�������R"NOR+HIY"�z"HIR"�������Y�W�V�|���K��I\n"NOR, me, target);
    if( me->query_stat("hp") > 6000 ) {
        raiseDamage = sk*2 + 1500 + me->query_skill("special", 1);
    } else {
        raiseDamage = sk*2 + me->query_stat("hp")/4 + me->query_skill("special", 1);
    }
    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    if( !COMBAT_D->isHit(me, target) ) {
        message_vision("\t$N�v���ݬ�F�����~�׶}���ۡA�o�]�Q�D�˨��@�ڪ�$n�~�F�@���I\n", target, me);
        me->start_busy(2);
    } else {
        me->damage_stat("mp", sk/4, me);
        target->receive_damage(damage, me);
        message_vision( sprintf("\t���Y���֦a��V$n�u�P�P�v�s��X�n�A$N���w�Q�W�����ۡA��y�p�`(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
        me->start_busy(1);
        me->improve_skill(SKILL_NAME, 1);
    }
    i = sk + random(200);
    me->receive_damage(i, me);
    write("\n�]���ҥ�˨��@�ڪ����~���ɳy���ۨ�"HIR"("+i+")"NOR"�I�ˮ`�C\n\n");
    return;
}
// �ϥε���
int perform_action(object me, string act, object target)
{
    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΡC\n");

    if( !me->query_condition("ticket") ) return notify_fail("�A�S���ϥΥ���ɶU���ޯ���C\n");

    switch( act ) {
        case "attack":
            if( !objectp(me) || !objectp(target) ) return notify_fail("�S����⤣��ϥΧ����ޯ�C\n");

            if( me->query_temp("ticket_card/ton") ) do_ton(me, target);
            else if( me->query_temp("ticket_card/spider") ) do_spider(me, target);
            else if( me->query_temp("ticket_card/wheya") ) do_wheya(me, target);
            else return notify_fail("�A�èS���ϥΧ������ɶU�ޯ�C\n");

            return 1;
            break;

        case "guard":
            if( !objectp(me) ) return 0;

            if( me->query_temp("ticket_card/rain") ) do_rain(me);
            else if( me->query_temp("ticket_card/music") ) do_music(me);
            else if( me->query_temp("ticket_card/bow") ) do_bow(me);
            else return notify_fail("�A�èS���ϥΫO�@���ɶU�ޯ�C\n");

            return 1;
            break;

        default: return notify_fail("�ثe�ɶU����������� attack �P�O�@�� guard ��إ\��C\n"); break;
    } return notify_fail("�ޯ���O�� perform lending ticket.attack|guard�C\n");
}
