#include <ansi.h>
#define SKILL_NAME "born-again branch"
#define SKILL_NAME_C "��K����"
#define SKILL_CLASS "operation"

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

// �_��\�K
void do_born(object me, int sk, int two)
{
    object branch, tree;
    int i, j = 0;

    branch = present("_WITHERED_", me);

    if( !objectp(branch) ) {
        write("�A���W�ڥ��S���\�K�C\n");
        return;
    }

    if( me->query_skill("operation") < 50 || me->query_skill("blood-cell revive") < 15 ) {
        write("�A����O�����H�ϥγo�@�ۡC\n");
        return;
    }

    if( !two ) two = 1;
    if( two > sk/20 ) {
        write("�w�A�ثe"+SKILL_NAME_C+"���{�סA�@���u��A�� "YEL+sk/20+NOR" �ڬ\�K�C\n");
        return;
    }

    if( branch->query_amount() < two ) {
        write("�A���W���\�K�ڥ������A�͡C\n");
        return;
    }

    if( me->query_stat("mp") < two*5 ) {
        write("�A���]�O�����H�A�ͧA���w�ƶq���\�K�C\n");
        return;
    }

    if( me->is_fighting() ) {
        write("�԰����L�k���ߦA�ͬ\�K�C\n");
        return;
    }
    message_vision(YEL"\n$N�N"NOR+branch->query("name")+YEL"�\�b��ߤW�A�w�w���a�����g�ߺc��...\n"NOR, me);
    tell_object(me, "\n");

    for(i=0;i<two;i++) {
        if( random(me->query_skill("blood-cell revive")) < random(50) ) {
            tell_object(me,HIR"���O�A�L���ļ�A�Ϭ\�K�o��L�h�����O�ӯ}�H�I\n"NOR);
            branch->add_amount(-1);
            if( !branch->query_amount() ) destruct(branch);
        } else {
            tell_object(this_player(),HIY"��K������o�ͩR�A�C��v���ܪ��A�A�A���F�L�ӡC\n"NOR);
            j++;
            branch->add_amount(-1);
            if( !branch->query_amount() ) destruct(branch);
        }
    }
    tell_object(me, "\n");
    message_vision(HIG"$N���^���O�A���G�s�@�����F\n\n"NOR, me);
    if( j >= 1 ) {
        tree = new(_DIR_AREA_"thorn_pine/npc/item/branch.c");
        if( !present("_BRANCH_", me) ) tree->set_amount(j);
        else tree->add_amount(j-1);
        if( !tree->move(me) ) {
            if( environment(me)->is_area() ) move_side(tree, me);
            else tree->move(environment(me));
            tell_object(me,HIY"(�A���W�ӭ��A��K�]�����b�a�W�C)\n"NOR);
        }
    }
    me->damage_stat("mp", two*5, me);
    me->start_busy(2);
    return;
}

// �شӤp��
void do_crop(object me, int sk)
{
    object branch, tree;

    tree = new(__DIR__"obj/tree_obj.c");
    branch = present("_BRANCH_", me);

    if( me->query_skill("operation") < 60 ) {
        write("�A����O�����H�ϥγo�@�ۡC\n");
        return;
    }
    if( me->query_stat("mp") < sk/10 ) {
        write("�A�����A�L�k�ϥ�"+SKILL_NAME_C+"�C\n");
        return;
    }
    if( objectp(me->query_temp("TREE_ONE")) ) {
        write("�A�w�g�b�شӾ�F�C\n");
        return;
    }
    if( objectp(me->query_temp("TREE_TWO")) ) {
        write("�A�w�g�b���a�@���H�F�C\n");
        return;
    }
    if( me->is_fighting() ) {
        write("�԰����ٴӾ�I�ĤH�i�S����n�ߵ��A�I\n");
        return;
    }
    // �������W���S����K
    if( !objectp(branch) ) {
        write("�A���W�S����K�n������h�ءC\n");
        return;
    }

    message_vision("\n$N�N"+branch->query("name")+"��b�a�W�A�þ��a"+branch->query("name")+"�w�w���J�a���C\n\n"NOR, me);
    if( !objectp(tree) ) {
        write("�]��������]�A�شӥ��ѤF...\n");
        destruct(tree);
        return;
    }
    if( environment(me)->is_area() ) {
        if( !area_move(environment(me), tree, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
            write("�A�ҺشӪ��𩿵M�ֳt�\\��F...\n");
            destruct(tree);
            return;
        }
    } else {
        if( !tree->move(environment(me)) ) {
            write("�A�ҺشӪ��𩿵M�ֳt�\\��F...\n");
            destruct(tree);
            return;
        }
    }
    // �Ӽƴ��
    branch->add_amount(-1);
    if( !branch->query_amount() ) destruct(branch);

    me->set_temp("TREE_ONE", tree);
    tree->set_owner(me);                      // �]�wowner

    // �W�[�ޯ�g��
    me->damage_stat("mp", sk/10, me);
    me->improve_skill(SKILL_NAME, 1);
    me->start_busy(3);
    return;
}

// ��@����H
void do_arise(object me, int sk)
{
    int lv, hair;
    object water, ob;

    ob = present("_TREE_", environment(me));

    if( me->query_skill("blood-cell revive") < 40 || sk < 30 ) {
        write("�A����O�����H�ϥγo�@�ۡC\n");
        return;
    }
    if( me->query_stat("mp") < sk/5 ) {
        write("�A�����A�L�k�ϥ�"+SKILL_NAME_C+"�C\n");
        return;
    }
    if( objectp(me->query_temp("TREE_TWO")) ) {
        write("�A�w�g�b���a�@���H�F�C\n");
        return;
    }
    if( me->is_fighting() ) {
        write("�԰����O�L�k���ߥh��@���C\n");
        return;
    }
    if( !ob ) {
        write("�o�̤S�S��������A��@�C\n");
        return;
    }

    // �ޯ�v�T��H���j��
    // �P���~�N�P�B�A�אּ�̺��O60��
    lv = (me->query_skill(SKILL_NAME)/10)*3;

    // �̵��Ŵ��ɯ�O
    // �𥻨����|�����A�u�����z���¤O�A�ҥH�ݩʲ���
    ob->set("no_fight", 0);
    ob->set_level(lv);
    ob->set_attr("str", lv*2);
    ob->set_attr("con", lv*2);
    ob->set_attr("dex", lv*2);
    ob->set_attr("int", lv*2);
    ob->set_stat_maximum("ap", lv*50);
    ob->set_stat_maximum("mp", lv*50);
    ob->set_stat_current("ap", lv*50);
    ob->set_stat_current("mp", lv*50);
    ob->set_skill("parry", lv*3);
    ob->set_skill("dodge", lv*3);

    // ��֤@�Ǩǧ𨾧ޥ�
    ob->add_temp("apply/intimidate", -50);
    ob->add_temp("apply/wittiness", -50);

    // ��H�O���|������
    ob->set("no_combat", 1);

    // �����O�έ��ؾ�G
    if( objectp(water = present("_HIY_WATER_", me)) ) {
        message_vision("$N���_"+water->query("name")+"�x�V�a����B�Ω��O��@"+ob->query("name")+"...\n\n"NOR, me);
        ob->set_name(HIY"������H"NOR, ({ me->query_id() + "'s golden veggie", "veggie", "_VEGGIE_"+me->query_id() }));
        ob->set("long", "�@�ʧ��Ӫ��j��A�W�������F�����{�{�������𸭡C\n");
        ob->set_stat_maximum("hp", lv*100);
        ob->set_stat_current("hp", lv*100);
    } else if( objectp(water = present("_HIR_WATER_", me)) ) {
        message_vision("$N���_"+water->query("name")+"�x�V�a����B�Ω��O��@"+ob->query("name")+"...\n\n"NOR, me);
        ob->set_name(HIR"�����H"NOR, ({ me->query_id() + "'s blood veggie", "veggie", "_VEGGIE_"+me->query_id() }));
        ob->set("long", "�@�ʧ��Ӫ��j��A�����b�����Ӯg�U�n�������A��C\n");
        ob->set_stat_maximum("hp", lv*90);
        ob->set_stat_current("hp", lv*90);
    } else if( objectp(water = present("_HIM_WATER_", me)) ) {
        message_vision("$N���_"+water->query("name")+"�x�V�a����B�Ω��O��@"+ob->query("name")+"...\n\n"NOR, me);
        ob->set_name(HIM"����H"NOR, ({ me->query_id() + "'s sakura veggie", "veggie", "_VEGGIE_"+me->query_id() }));
        ob->set("long", "�@�ʧ��Ӫ��j��A�N������뤣�_�a�Ƹ������⪺��ä�C\n");
        ob->set_stat_maximum("hp", lv*70);
        ob->set_stat_current("hp", lv*70);
    } else if( objectp(water = present("_HIG_WATER_", me)) ) {
        message_vision("$N���_"+water->query("name")+"�x�V�a����B�Ω��O��@"+ob->query("name")+"...\n\n"NOR, me);
        ob->set_name(HIG"�`���H"NOR, ({ me->query_id() + "'s green veggie", "veggie", "_VEGGIE_"+me->query_id() }));
        ob->set("long", "�@�ʧ��Ӫ��j��A�A���C���ҩ��F�����;��C\n");
        ob->set_stat_maximum("hp", lv*50);
        ob->set_stat_current("hp", lv*50);
    } else {
        write("�A���W�S����G������@�p��C\n");
        return;
    }
    water->add_amount(-1);
    if( !water->query_amount() ) destruct(water);

    if( me->query_skill("hair order") > 19 ) {
        hair = me->query_skill("hair order") - (random(20) + 1);
        ob->set_skill("hair order", hair);
    }

    // �𵹥L�h�@�I���m��O
    // ��������ҥH�N�����O�ɨ����m
    // ���L���F���v�T���z���¤O�A�ҥH�����O������
    ob->add_temp("apply/armor", ob->query_ability("attack"));

    ob->set_leader(me);                     // ���Hleader
    ob->set_owner(me);                      // �]�wowner
    ob->set("change",1);                    // ��

    me->start_busy(5);
    me->improve_skill(SKILL_NAME, 1);
    me->set_temp("TREE_TWO", ob);
    me->damage_stat("mp", sk/5, me);

    ob->guard_ob(me);                       // �O�@leader
    return;
}

// ���o�ˮ`
int getDamage(object me, object target, int sk, object ob)
{
    int damage, raiseDamage;
    object wp;

    if( sk < 80 ) raiseDamage = ob->query_stat_maximum("hp")/10;
    if( sk < 140 ) raiseDamage = ob->query_stat_maximum("hp")/9;
    if( sk < 200 ) raiseDamage = ob->query_stat_maximum("hp")/8;
    else raiseDamage = ob->query_stat_maximum("hp")/6;

    raiseDamage += sk + me->query_skill("operation");
    if( raiseDamage >= 2000 ) raiseDamage = 2000;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// ��H���z
int GameOver(object me, object target, int sk, string act)
{
    object ob;
    int damage;

    ob = present("_VEGGIE_"+me->query_id(), environment(me));

    if( !objectp(me) || !objectp(target) ) {
        tell_object(me, "�A�������w�@�ӥؼЦ��z�C\n");
        return 0;
    }

    if( !ob ) {
        tell_object(me, "�A�ڥ��N�S����H�i�H����C\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "�S���b�԰��٬�����H�C\n");
        return 0;
    }

    if( ob->query("WILL_DIE") == 1 ) {
        tell_object(me, "��H�w�g�֭n���h�F�C\n");
        return 0;
    }

    message_vision("$N�V��@�D�B�Ω��O���a"+ob->query("name")+"����ʡA�u��"+ob->query("name")+"�ߨ����Y�ĦV$n�I\n\n"NOR, me, target);

    damage = getDamage(me, target, sk, ob);

    target->receive_damage(damage, me);
    message_vision( ob->query("name")+HIW"�C��K�}����"NOR"$n"HIW"���A���骺���߶}�l�o�X"HIR+BLINK"������~"NOR+HIW"�I\n"NOR, me, target);
    message_vision( sprintf("�u�T�v�u�G�v�u�@�v�F�����T�N$n�����|������(%d) %s\n\n", damage, COMBAT_D->report_status(target)), me, target);

    // ����mp, �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);
    me->delete_temp("TREE_ONE");
    me->delete_temp("TREE_TWO");
    ob->set("WILL_DIE", 1);
    ob->do_destruct();
    return 1;
}

int perform_action(object me, string act, object target)
{
    int sk, two;
    string one;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���Ũϥ�"+SKILL_NAME_C+"�C\n");

    if( !act || sscanf(act, "%s %d", one, two) != 2 ) {
        if( !act || sscanf(act, "%s", one) != 1 ) {
            tell_object(me, "�ثe"+SKILL_NAME_C+"�� born, crop, arise, over �|�إ\\��C\n");
            return 1;
        }
    }
    switch( one ) {
        case "born": do_born(me, sk, two); break;
        case "crop": do_crop(me, sk); break;
        case "arise": do_arise(me, sk); break;
        case "over": GameOver(me, target, sk, act); break;
        default: return notify_fail("�ثe"+SKILL_NAME_C+"�� born, crop, arise, over �|�إ\\��C\n"); break;
    }
    return 1;
}