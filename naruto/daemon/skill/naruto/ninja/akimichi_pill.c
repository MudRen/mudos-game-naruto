/* ��D����(akimichi pill) 
   by mouse 2007/8/13
*/

#include <ansi.h>
#define SKILL_NAME "akimichi pill"
#define SKILL_NAME_C "��D����"
#define SKILL_CLASS "ninja"

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
int isCast(object me, string act)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A���b���L����s�@��D���ġC\n");
        return 0;
    }

    if( me->is_fighting() ) {
        tell_object(me, "�԰����ٯ���߻s�ġH\n");
        return 0;
    }

    if( me->query_skill(SKILL_NAME) < 60 ) {
        tell_object(me, "�A��" + SKILL_NAME_C + "���Ѥ����A���|�s�ġC\n");
        return 0;
    }
    return 1;
}

// �Ե�Y�s�@
void do_holenso(object me, int two)
{
    int i, sk;
    object a, b, c, d, e, item;
    if( two <= 1 ) two = 1;
    sk = me->query_skill(SKILL_NAME, 1);

    if( two > sk/20 ) {
        write("�A���ĲڨS����j�A����@���s�@�o��h�Y�l�C\n");
        return;
    }
    message_vision(CYN"$N��@����ƥ���Ĳڸ̡A�ΤO�V���n�̤����D�b��ԣ...\n"NOR, me);

    for(i=0;i<two;i++) {
        if( !objectp(a = present("_HOLENSO_A_", me)) ||
            !objectp(b = present("_HOLENSO_B_", me)) ||
            !objectp(c = present("_HOLENSO_C_", me)) ||
            !objectp(d = present("_PILL_SOY_", me)) ||
            !objectp(e = present("_PILL_SUGAR_", me)) ) {

            write("�A�����ƷǳƤ������A�L�k�s�@�Ե�Y�C\n");
            break;
        }
        if( me->query_stat("ap") < 10 ) {
            write("�A����O�����F�A�𮧤@�U�A�~��a�C\n");
            break;
        }
        a->add_amount(-1);
        if( !a->query_amount() ) destruct(a);
        b->add_amount(-1);
        if( !b->query_amount() ) destruct(b);
        c->add_amount(-1);
        if( !c->query_amount() ) destruct(c);
        d->add_amount(-1);
        if( !d->query_amount() ) destruct(d);
        e->add_amount(-1);
        if( !e->query_amount() ) destruct(e);

        me->damage_stat("ap", 10, me);

        item = new("/daemon/skill/naruto/ninja/obj/pill_holenso.c");
        if( item->move(me) ) tell_object(me,HIG"(�A���\\���s�@�F�@���Ե�Y)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIG"(�A���\\���s�@�F�@���Ե�Y�A���O���b�a�W�F)\n"NOR);
        }
    }
    me->start_busy(5);
    return;
}

// �@���Y�s�@
void do_kare(object me, int two)
{
    int i, sk;
    object a, b, c, d, e, item;
    if( two <= 1 ) two = 1;
    sk = me->query_skill(SKILL_NAME, 1);

    if( two > sk/20 ) {
        write("�A���ĲڨS����j�A����@���s�@�o��h�Y�l�C\n");
        return;
    }
    message_vision(CYN"$N��@����ƥ���Ĳڸ̡A�ΤO�V���n�̤����D�b��ԣ...\n"NOR, me);

    for(i=0;i<two;i++) {
        if( !objectp(a = present("_KARE_A_", me)) ||
            !objectp(b = present("_KARE_B_", me)) ||
            !objectp(c = present("_KARE_C_", me)) ||
            !objectp(d = present("_KARE_D_", me)) ||
            !objectp(e = present("_PILL_SUGAR_", me)) ) {

            write("�A�����ƷǳƤ������A�L�k�s�@�@���Y�C\n");
            break;
        }
        if( me->query_stat("ap") < 15 ) {
            write("�A����O�����F�A�𮧤@�U�A�~��a�C\n");
            break;
        }
        a->add_amount(-1);
        if( !a->query_amount() ) destruct(a);
        b->add_amount(-1);
        if( !b->query_amount() ) destruct(b);
        c->add_amount(-1);
        if( !c->query_amount() ) destruct(c);
        d->add_amount(-1);
        if( !d->query_amount() ) destruct(d);
        e->add_amount(-1);
        if( !e->query_amount() ) destruct(e);

        me->damage_stat("ap", 15, me);

        item = new("/daemon/skill/naruto/ninja/obj/pill_kare.c");
        if( item->move(me) ) tell_object(me,HIY"(�A���\\���s�@�F�@���@���Y)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIY"(�A���\\���s�@�F�@���@���Y�A���O���b�a�W�F)\n"NOR);
        }
    }
    me->start_busy(5);
    return;
}

// ���ԤY�s�@
void do_chili(object me, int two)
{
    int i, sk;
    object a, b, c, d, e, f, item;
    if( two <= 1 ) two = 1;
    sk = me->query_skill(SKILL_NAME, 1);

    if( two > sk/20 ) {
        write("�A���ĲڨS����j�A����@���s�@�o��h�Y�l�C\n");
        return;
    }
    message_vision(CYN"$N��@����ƥ���Ĳڸ̡A�ΤO�V���n�̤����D�b��ԣ...\n"NOR, me);

    for(i=0;i<two;i++) {
        if( !objectp(a = present("_CHILI_A_", me)) ||
            !objectp(b = present("_CHILI_B_", me)) ||
            !objectp(c = present("_CHILI_C_", me)) ||
            !objectp(d = present("_CHILI_D_", me)) ||
            !objectp(e = present("_CHILI_E_", me)) ||
            !objectp(f = present("_PILL_SOY_", me)) ) {

            write("�A�����ƷǳƤ������A�L�k�s�@���ԤY�C\n");
            break;
        }
        if( me->query_stat("ap") < 20 ) {
            write("�A����O�����F�A�𮧤@�U�A�~��a�C\n");
            break;
        }
        a->add_amount(-1);
        if( !a->query_amount() ) destruct(a);
        b->add_amount(-1);
        if( !b->query_amount() ) destruct(b);
        c->add_amount(-1);
        if( !c->query_amount() ) destruct(c);
        d->add_amount(-1);
        if( !d->query_amount() ) destruct(d);
        e->add_amount(-1);
        if( !e->query_amount() ) destruct(e);
        f->add_amount(-1);
        if( !f->query_amount() ) destruct(f);

        me->damage_stat("ap", 20, me);

        item = new("/daemon/skill/naruto/ninja/obj/pill_chili.c");
        if( item->move(me) ) tell_object(me,HIR"(�A���\\���s�@�F�@�����ԤY)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIR"(�A���\\���s�@�F�@�����ԤY�A���O���b�a�W�F)\n"NOR);
        }
    }
    me->start_busy(5);
    return;
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    string one;
    int two;

    if( !act || sscanf(act, "%s %d", one, two) != 2 ) {
        if( !act || sscanf(act, "%s", one) != 1 ) {
            tell_object(me, "���O�榡�Rperform akimichi pill.<�Y�l> <�ƶq>\n");
            return 0;
        }
    }
    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act) ) return 1;

    switch( one ) {
        case "holenso": do_holenso(me, two); break;
        case "kare": do_kare(me, two);  break;
        case "chili": do_chili(me, two);  break;
        default: return notify_fail("�ثe��D���ĥu�� holenso�Bkare�Bchili �T�ؤY�l�C\n���O�榡�Rperform akimichi pill.<�Y�l> <�ƶq>\n"); break;
    }
    return 1;
}