// 龍頭戲畫的短CD

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("dragon_draw_cd");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        tell_object(me, NOR"[你的精神似乎好多了。]\n"NOR);
        me->delete_condition(cnd);
        return;
    }
}