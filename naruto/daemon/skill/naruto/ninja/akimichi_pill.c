/* 秋道秘藥(akimichi pill) 
   by mouse 2007/8/13
*/

#include <ansi.h>
#define SKILL_NAME "akimichi pill"
#define SKILL_NAME_C "秋道秘藥"
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
        case 189: me->set_skill_require(skill, 1500000); break; // 關卡3 : 189升190
        case 149: me->set_skill_require(skill, 1000000); break; // 關卡2 : 149升150
        case  99: me->set_skill_require(skill, 500000);  break; // 關卡1 :  99升100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// 檢查是否能使用技能
int isCast(object me, string act)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你正在忙碌不能製作秋道秘藥。\n");
        return 0;
    }

    if( me->is_fighting() ) {
        tell_object(me, "戰鬥中還能分心製藥？\n");
        return 0;
    }

    if( me->query_skill(SKILL_NAME) < 60 ) {
        tell_object(me, "你的" + SKILL_NAME_C + "知識不足，不會製藥。\n");
        return 0;
    }
    return 1;
}

// 菠菜丸製作
void do_holenso(object me, int two)
{
    int i, sk;
    object a, b, c, d, e, item;
    if( two <= 1 ) two = 1;
    sk = me->query_skill(SKILL_NAME, 1);

    if( two > sk/20 ) {
        write("你的藥缽沒那麼大，不能一次製作這麼多丸子。\n");
        return;
    }
    message_vision(CYN"$N把一堆材料丟到藥缽裡，用力敲打搖晃不知道在做啥...\n"NOR, me);

    for(i=0;i<two;i++) {
        if( !objectp(a = present("_HOLENSO_A_", me)) ||
            !objectp(b = present("_HOLENSO_B_", me)) ||
            !objectp(c = present("_HOLENSO_C_", me)) ||
            !objectp(d = present("_PILL_SOY_", me)) ||
            !objectp(e = present("_PILL_SUGAR_", me)) ) {

            write("你的材料準備不完全，無法製作菠菜丸。\n");
            break;
        }
        if( me->query_stat("ap") < 10 ) {
            write("你的精力不夠了，休息一下再繼續吧。\n");
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
        if( item->move(me) ) tell_object(me,HIG"(你成功\的製作了一顆菠菜丸)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIG"(你成功\的製作了一顆菠菜丸，但是掉在地上了)\n"NOR);
        }
    }
    me->start_busy(5);
    return;
}

// 咖哩丸製作
void do_kare(object me, int two)
{
    int i, sk;
    object a, b, c, d, e, item;
    if( two <= 1 ) two = 1;
    sk = me->query_skill(SKILL_NAME, 1);

    if( two > sk/20 ) {
        write("你的藥缽沒那麼大，不能一次製作這麼多丸子。\n");
        return;
    }
    message_vision(CYN"$N把一堆材料丟到藥缽裡，用力敲打搖晃不知道在做啥...\n"NOR, me);

    for(i=0;i<two;i++) {
        if( !objectp(a = present("_KARE_A_", me)) ||
            !objectp(b = present("_KARE_B_", me)) ||
            !objectp(c = present("_KARE_C_", me)) ||
            !objectp(d = present("_KARE_D_", me)) ||
            !objectp(e = present("_PILL_SUGAR_", me)) ) {

            write("你的材料準備不完全，無法製作咖哩丸。\n");
            break;
        }
        if( me->query_stat("ap") < 15 ) {
            write("你的精力不夠了，休息一下再繼續吧。\n");
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
        if( item->move(me) ) tell_object(me,HIY"(你成功\的製作了一顆咖哩丸)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIY"(你成功\的製作了一顆咖哩丸，但是掉在地上了)\n"NOR);
        }
    }
    me->start_busy(5);
    return;
}

// 辣椒丸製作
void do_chili(object me, int two)
{
    int i, sk;
    object a, b, c, d, e, f, item;
    if( two <= 1 ) two = 1;
    sk = me->query_skill(SKILL_NAME, 1);

    if( two > sk/20 ) {
        write("你的藥缽沒那麼大，不能一次製作這麼多丸子。\n");
        return;
    }
    message_vision(CYN"$N把一堆材料丟到藥缽裡，用力敲打搖晃不知道在做啥...\n"NOR, me);

    for(i=0;i<two;i++) {
        if( !objectp(a = present("_CHILI_A_", me)) ||
            !objectp(b = present("_CHILI_B_", me)) ||
            !objectp(c = present("_CHILI_C_", me)) ||
            !objectp(d = present("_CHILI_D_", me)) ||
            !objectp(e = present("_CHILI_E_", me)) ||
            !objectp(f = present("_PILL_SOY_", me)) ) {

            write("你的材料準備不完全，無法製作辣椒丸。\n");
            break;
        }
        if( me->query_stat("ap") < 20 ) {
            write("你的精力不夠了，休息一下再繼續吧。\n");
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
        if( item->move(me) ) tell_object(me,HIR"(你成功\的製作了一顆辣椒丸)\n"NOR);
        else {
            if( environment(me)->is_area() ) move_side(item, me);
            else item->move(environment(me));
            tell_object(me,HIR"(你成功\的製作了一顆辣椒丸，但是掉在地上了)\n"NOR);
        }
    }
    me->start_busy(5);
    return;
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    string one;
    int two;

    if( !act || sscanf(act, "%s %d", one, two) != 2 ) {
        if( !act || sscanf(act, "%s", one) != 1 ) {
            tell_object(me, "指令格式﹕perform akimichi pill.<丸子> <數量>\n");
            return 0;
        }
    }
    // 檢查是否能使用技能
    if( !isCast(me, act) ) return 1;

    switch( one ) {
        case "holenso": do_holenso(me, two); break;
        case "kare": do_kare(me, two);  break;
        case "chili": do_chili(me, two);  break;
        default: return notify_fail("目前秋道秘藥只有 holenso、kare、chili 三種丸子。\n指令格式﹕perform akimichi pill.<丸子> <數量>\n"); break;
    }
    return 1;
}