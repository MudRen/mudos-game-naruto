#include <ansi.h>
#define SKILL_NAME "almighty creation"
#define SKILL_NAME_C "�L�����C�s"
#define SKILL_CLASS "concrete"

inherit SKILL;

string *name = ({ HIW"�G���C"NOR, HIR"�O�s�C"NOR, HIW"����"NOR"���C",
                  HIY"�·G�صܤh���C"NOR, HIK"�׵���"NOR, HIC"��ù"HIW"���C"NOR,
                  HIW"��o���b�C"NOR, YEL"��ߤ�"HIC"�d�z���C"NOR, "���K�i�h",
                  HIK"�·t���C"NOR, HIY"�ͼ����C"NOR, HIG"ù���~���C"NOR,
                  HIM"�@��"NOR"���C", HIW"�M�h���C"NOR, HIK"�¤��l"HIW"�R�w�ؤ��C"NOR,
                  YEL"�j�J��"HIY"���C"NOR, HIW"���Z�h"NOR, RED"�]��"HIK"����"NOR,
                  "�Xù���J-"RED"�������C"NOR, "�ڤh�F�C", YEL"�त�C"NOR,
                  "����ù��-"HIK"�·t���C"NOR, HIW"�u�@"HIM"���̤��C"NOR, "���s�C",
                  "�ۤ��C", HIW"�ջ�"NOR"�M�h�C", HIK"�ªZ�h���C"NOR, });

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

// ���o�ˮ`
int getDamage(object me, object target, int sk, object sword)
{
    string msg = "";
    int damage, num, count = 0, *arr = allocate(10);

    message_vision("\n$N�|�_"+sword->query("name")+"��@�C���A��$n�o�ʩT������"HIY"�y"HIW+BLINK"�����]�_"NOR+HIY"�z\n\n"NOR, me, target);

    num = sk/40 + random(3);

    while(count < num) {
        arr[count] = random(27);
        if( member_array(arr[count], arr) == count) {
            if(count == num - 1) msg += name[arr[count]];
            else msg += name[arr[count]] + "�B";
            count++;
        }
    }
    // �l�Ӫ��C�ƶq��������v�T
    damage = sk*(num+1) + me->query_skill("concrete")*2;
    message_vision("�u��"+msg+"���C����"+sword->query("name")+"�l���Ө�|�P\n"NOR, target);

    return damage;
}

// �p��O�_�R��
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1) + COMBAT_D->wittiness(target, 1)/2;
    j = COMBAT_D->intimidate(target, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// �ޯ�ϥΫ� 
void setEffect(object me, int sk, object sword)
{
    mapping cnd = ([]);

    me->damage_stat("mp", 20, me);
    me->improve_skill(SKILL_NAME, 1);
    destruct(sword);

    cnd["name"] = HIY"(CD)�]�_"NOR;
    cnd["duration"] = 60;

    me->set_condition("diabo_busy", cnd);
}

void do_destruct(object me)
{
    object sword;

    // ���C�|���¼C�R�h
    if( objectp(sword = present("_CREATION_SWORD_", me)) ) {
        message_vision("\n$N�N�C�����O���^�A"+sword->query("name")+"���������F�C\n\n"NOR, me);
        destruct(sword);
    } else {
        write("�A���W�ڥ��S����v�C�C\n");
        return;
    }
    return;
}

// �гy�Z��
void do_perform(object me)
{
    string msg;
    int sk, concrete, i, j;
    object shadow, sword;

    sk = me->query_skill(SKILL_NAME, 1);
    concrete = me->query_skill("concrete", 1);

    if( concrete < 60 ) {
        write("�A����{�Ƶ{�פ����H�ϥΧ�v�C\n");
        return;
    }
    if( sk < 30 ) {
        write("�A���ޯ൥�Ť����H�ϥΧ�v�C\n");
        return;
    }
    // �֦��̮����@�ǩ��O
    if( me->query_stat("mp") < 200 ) {
        write("�A�����O�����C\n");
        return;
    }
    if( me->is_busy() ) {
        write("�A�ȮɵL�k�����믫�ϥΧ�v�C\n");
        return;
    }
    // ���������W�O�_�w�g���C�F, ���C�|���¼C�R�h
    if( objectp(sword = present("_CREATION_SWORD_", me)) ) {
        message_vision("\n$N�N�C�����O���^�A"+sword->query("name")+"���������F�C\n\n"NOR, me);
        destruct(sword);
    }
    shadow = new(__DIR__"obj/sword_obj.c");

    if( !objectp(shadow) ) {
        write("�A���G�L�k��{���\...\n");
        destruct(shadow);
        return;
    }
    message_vision("$N���W�����w�w��D�G"HIG"��v�E�}�l...�c�y�ѩ�...\n"NOR, me);
    if( !shadow->move(me) ) {
        write("�A�����W�ӭ��F�A�L�k�A���ʧ�h���Z��\n");
        destruct(shadow);
        return;
    }

    i = random(4);
    j = random(4);

    shadow->set_name(name[random(sizeof(name))], ({ "famed sword", "sword", "_CREATION_SWORD_" }));
    shadow->setup_weapon(sk/3+concrete/6+random(5), sk/2+concrete/4+random(10), 100, 1);
    shadow->set("long", "�g�ѧ�v�Ҩ�{�X�Ӫ��W�C�A�O�_�֦���گ�O�h���o�Ӫ��C\n" );

    switch( i ) {
        case 0: shadow->set("apply_weapon/righthand/attack", sk/10); break;
        case 1: shadow->set("apply_weapon/righthand/armor", sk/10); break;
        case 2: shadow->set("apply_weapon/righthand/intimidate", sk/10); break;
        case 3: shadow->set("apply_weapon/righthand/wittiness", sk/10); break;
    }
    while( j == i ) {
        j = random(4);
    }
    switch( j ) {
        case 0: shadow->set("apply_weapon/righthand/attack", sk/20); break;
        case 1: shadow->set("apply_weapon/righthand/armor", sk/20); break;
        case 2: shadow->set("apply_weapon/righthand/intimidate", sk/20); break;
        case 3: shadow->set("apply_weapon/righthand/wittiness", sk/20); break;
    }
    switch( i + j ) {
        case 0: msg = "�P�_���~�A�Ч�Ův�B�z"; break;
        case 1: msg = ""HIM"���Ť���"; break;
        case 2: msg = ""RED"���ɤ���"; break;
        case 3: if( i == 0 || i == 3 ) msg = ""HIC"í������";
                else msg = ""HIG"���W����";
                break;
        case 4: msg = ""BLU"�I�ۤ���"; break;
        case 5: msg = ""HIB"��Ԥ���"; break;
    }
    if( random(2) == 1 ) shadow->set("apply_weapon/righthand/hp", random(sk));
    else shadow->set("apply_weapon/righthand/ap", random(sk));
    shadow->wield("righthand");
    message_vision(HIW"�u���@�����"+msg+HIW"��"NOR+shadow->query("name")+HIW"�b$N�⤤�v�����ΡA�̫�ש�ɥG����������ƤF�C\n"NOR, me);
    me->damage_stat("mp", 200, me);

    // �b�԰����s�C�| busy ������[
    if( me->is_fighting() ) {
        write("�A�b�԰������ߨϥΧ�v�A�@�ɶ��L�k�����I\n");
        me->start_busy(6);
    } else me->start_busy(3);

    me->set_temp("CREATION_SWORD", shadow);

    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);

    return;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    string skill;
    int damage, raiseDamage, sk, hit;
    object sword;
    mapping weapons;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΡC\n");

    if( act != "rain" ) {
        switch( act ) {
            case "gz": do_perform(me); return 1; break;
            case "destruct": do_destruct(me); return 1; break;
            default: return notify_fail("�ثe"+SKILL_NAME_C+"�� gz, rain, destruct �T�إ\\��C\n"); break;
        }
    }
    if( !objectp(me) || !objectp(target) ) return notify_fail("�ثe"+SKILL_NAME_C+"�� gz, rain, destruct �T�إ\\��C\n");

    if( !me->is_fighting(target) )
        return notify_fail("�԰�������F�ٷQ������C\n");

    // �ɥδc�]���}�N�o�ɶ�
    if( me->query_condition("diabo_busy", 1) != 0)
        return notify_fail("�A�����g�L�@�q�ɶ���~��ϥΤ����]�_�C\n");

    // �����ϥΪ� mp �������ϥ�
    if( me->query_stat("mp") < 100 )
        return notify_fail("�A�����O�����H�ϥΤ����]�_�C\n");

    // �������S���s�C
    if( !objectp(sword = present("_CREATION_SWORD_", me)) )
        return notify_fail("�Q�ϥΤ����]�_���������C���C\n");

    // �C�n�����U�ӡA���M���[��O�|�O�d
    if( mapp(weapons = me->query_temp("weapon")) && sizeof(weapons) )
        foreach(skill, sword in weapons) sword->unequip();

    // �O�_�R��
    hit = isHit(me, target);

    // �p��ˮ`�A����ܥl�C�T���ҥH�\�b�~��
    raiseDamage = getDamage(me, target, sk, sword);

    if( hit ) {
        me->add_temp("apply/attack", raiseDamage);
        damage = COMBAT_D->isDamage(me, target, sword);
        me->add_temp("apply/attack", -raiseDamage);

        target->receive_damage(damage, me);
        message_vision( sprintf(HIR"���s���_���C�B�������V"NOR"$n"HIR"�A�N"NOR"$n"HIR"�릨�F�@�Ӧ�]�K�I(%d) %s\n\n", damage, COMBAT_D->report_status(target)), me, target);
        me->start_busy(1);
        target->start_busy(2);
    } else {
        message_vision("���O$N���W�����a�o�{�F�������}��A�ƸѤF���ۡC\n\n"NOR, target);
        me->start_busy(2);
    }
    setEffect(me, sk, sword);
    return 1;
}
