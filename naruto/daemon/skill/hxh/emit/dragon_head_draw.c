#include <ansi.h>
#define SKILL_NAME "dragon-head draw"
#define SKILL_NAME_C "�s�Y���e"
#define SKILL_CLASS "emit"

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

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }
    if( act != "summon" ) {
        tell_object(me, "�ثe�s�Y���e�� summon, advance, none �T�إ\\��C\n");
        return 0;
    }

    if( me->query_condition("dragon_draw_cd") ) {
        tell_object(me, "�]�����s�Q�}�a�ϧA�믫���СA�Ȯ��ٵL�k�l����s�C\n");
        return 0;
    }

    if( me->query_skill("emit", 1) < 80 ) {
        tell_object(me, "�A����O�����H�ϥγo�ӧޯ�C\n");
        return 0;
    }

    if( sk < 40 ) {
        tell_object(me, "�A��" + SKILL_NAME_C + "���Ť����A�L�k�ϥγo�ӧޯ�C\n");
        return 0;
    }

    if( me->query_stat("mp") < 50 ) {
        tell_object(me, "�A�ݭn�ܤ� 50 �I�����O�A�~��ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�A�����b�԰����~��������s�C\n");
        return 0;
    }

    if( objectp(me->query_temp("SUMMON_DRAGON")) ) {
        tell_object(me, "�A�w�g����X���s�F�C\n");
        return 0;
    }
    return 1;
}

void advance_dragon(object me, int a, int b, int c, int d)
{
    int sk, lv;

    if( me->query_skill(SKILL_NAME, 1) < 100 ) {
        tell_object(me, "�A����O�ٵL�k�۩w�ݩʡC\n");
        return;
    }
    sk = me->query_skill("emit", 1);
    lv = (me->query_skill(SKILL_NAME, 1)/10)*3;

    if( lv < me->query_level() + 5 ) {
        lv = (lv*150/100)*4 - (lv*40/60)*4;
        if( a + b + c + d > lv ) {
            tell_object(me, "���s���Ť����A�̦h�u��� "+chinese_number(lv)+" �I�C\n");
            return;
        }
    } else {
        lv = (me->query_level()*150/100)*4 - (me->query_level()*40/60)*4;
        if( a + b + c + d > lv ) {
            tell_object(me, "�ϥΪ̵��Ť����A�̦h�u��� "+chinese_number(lv)+" �I�C\n");
            return;
        }
    }

    if( a + b + c + d > sk ) {
        tell_object(me, "�A�ثe�̦h�u�൹���s��"+chinese_number(sk)+"�I�C\n");
        return;
    }

    if( lv == (me->query_skill(SKILL_NAME, 1)/10)*3 ) lv = sk;
    printf("�A�����s�ثe���I�]�w���G\n�O�q: %d, ���: %d, �ӱ�: %d, ���z: %d\n�̰��I�� "HIR"%d"NOR" �I�B�Ѿl�I�� "HIG"%d"NOR" �I�B������I�W�� "HIY"%d"NOR" �I\n"NOR, a, b, c, d, sk, lv - (a + b + c + d), lv );
    me->set("adv_dragon/str", a);
    me->set("adv_dragon/con", b);
    me->set("adv_dragon/dex", c);
    me->set("adv_dragon/int", d);
    return;
}

void advance_delete(object me, int sk)
{
    if( sk < 100 ) {
        tell_object(me, "�A����O�ٵL�k�۩w�ݩʡC\n");
        return;
    }

    write("�A�M�w�������s�ݩʧ��I���]�w\n");
    me->delete("adv_dragon");
    return;
}

// �˳Ƥ��P�_
void WieldClaw(object me, object shadow)
{
    int sk;
    object wp;

    wp = new(__DIR__"obj/claw.c");
    sk = (me->query_skill(SKILL_NAME) + me->query_skill("emit")/2)/2;

    wp->setup_weapon(sk, sk+10, 100, 1);
    wp->move(shadow);
    wp->wield("twohanded");
}

// �إߩ��s
void construct_shadow(object me, int sk)
{
    int lv, ntar, i;
    object shadow, wp;
    object* targets;

    targets = me->query_enemy();
    ntar = sizeof(targets);

    shadow = new(__DIR__"obj/dragon_obj.c");
    if( !objectp(shadow) ) {
        write("�A���G�L�k��{���\...\n");
        destruct(shadow);
        return;
    }
    message_vision("$N�����������O�I�i"HIY"�u�o�v"NOR"�u���q$N���W�ĥX�����O����"HIW"�ۤƦ��s��"NOR"...\n", me);

    if( environment(me)->is_area() ) {
        if( !area_move(environment(me), shadow, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
            write("���O�A���M�����O���������A���s�S�����F�C\n");
            destruct(shadow);
            return;
        }
    } else {
        if( !shadow->move(environment(me)) ) {
            write("���O�A���M�����O���������A���s�S�����F�C\n");
            destruct(shadow);
            return;
        }
    }
    // �ޯ�v�T�s���j��
    // �̰� 60 ��
    lv = (me->query_skill(SKILL_NAME)/10)*3;

    // �̵��Ŵ��ɯ�O
    // �H�U��Ԥ��@�ˡB�s�����ŷ|���D�H�v�T
    // �̰����|�W�L�D�H���� + 5
    if( lv <= me->query_level() + 5 ) shadow->set_level(lv);
    else shadow->set_level(me->query_level() + 5);

    // �ݩʥi�H�ۦ���I�A�u���򥻪��ݩʬO�T�w��
    // ����H�I�Ƥw�g��L�S���^ 99 ���ٯ���ݩʰt�m��
    if( me->query("adv_dragon") && sk > 99 ) {
        shadow->set_attr("str", lv*40/60 + me->query("adv_dragon/str"));
        shadow->set_attr("con", lv*40/60 + me->query("adv_dragon/con"));
        shadow->set_attr("dex", lv*40/60 + me->query("adv_dragon/dex"));
        shadow->set_attr("int", lv*40/60 + me->query("adv_dragon/int"));
    } else {
        shadow->set_attr("str", lv*150/100);
        shadow->set_attr("con", lv*150/100);
        shadow->set_attr("dex", lv*150/100);
        shadow->set_attr("int", lv*150/100);
    }

    // �s�u��b�԰����ϥΡAap �y�L�W�[�@��
    shadow->set_stat_maximum("ap", lv*60);
    shadow->set_stat_maximum("hp", lv*50);
    shadow->set_stat_maximum("mp", lv*50);
    shadow->set_stat_current("ap", lv*60);
    shadow->set_stat_current("hp", lv*50);
    shadow->set_stat_current("mp", lv*50);
    shadow->set_skill("combat", lv*3);
    shadow->set_skill("parry", lv*3);
    shadow->set_skill("dodge", lv*3);
    shadow->set_skill("heavy hit", lv*3);
    shadow->set_skill("savage hit", lv*3);
    shadow->set_skill("continual hit", lv*3);
    shadow->set_skill("strength", sk);
    shadow->set_skill("powerup", sk);

    // �W�٤��šA������O�]����
    switch( sk ) {
        case 0..99:
            shadow->set_name("�K�ҩ��s", ({ me->query_id() + "'s dragon", "dragon", "_DRAGON_NPC_" }));
            break;
        case 100..149:
            shadow->set_name(HIK"�ɥҩ��s"NOR, ({ me->query_id() + "'s dragon", "dragon", "_DRAGON_NPC_" }));
            WieldClaw(me, shadow);
            break;
        case 150..199:
            shadow->set_name(HIW"�ȥҩ��s"NOR, ({ me->query_id() + "'s dragon", "dragon", "_DRAGON_NPC_" }));
            shadow->add_temp("apply/intimidate", sk/8);
            WieldClaw(me, shadow);
            break;
        case 200:
            shadow->set_name(HIY"���ҩ��s"NOR, ({ me->query_id() + "'s dragon", "dragon", "_DRAGON_NPC_" }));
            shadow->add_temp("apply/intimidate", sk/4);
            WieldClaw(me, shadow);
            break;
    }
    shadow->do_heal();

    shadow->set_leader(me);     // ���Hleader
    shadow->set_owner(me);      // �]�wowner

    if( ntar > 0 ) {
        for(i=0;i<ntar;i++) {
            if( i == ntar ) break;          // ���@��
            shadow->kill_ob(targets[i]);    // �n��������ĤH
            targets[i]->kill_ob(shadow);
        }
    }
    me->set_temp("SUMMON_DRAGON", shadow);
    shadow->guard_ob(me);                   // �O�@leader
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk)
{
    me->improve_skill(SKILL_NAME, 1);
    me->damage_stat("mp", sk/4, me);
    me->start_busy(2);
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    int a, b, c, d, sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( act != "none" && act != "summon" ) {
        if( sscanf(act, "%s %d %d %d %d", act, a, b, c, d) == 5 ) {
            advance_dragon(me, a, b, c, d);
            return 1;
        } else if( act == "advance" ) {
            tell_object(me, "���O�榡�Rperform dragon-head draw.advance <�O�q> <���> <�ӱ�> <���z>\n");
            return 1;
        }
    }

    if( act == "none" ) {
        advance_delete(me, sk);
        return 1;
    }

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, target, sk) ) return 1;

    // �l����s
    construct_shadow(me, sk);

    // �ϥΫ�
    setEffect(me, sk);
    return 1;
}