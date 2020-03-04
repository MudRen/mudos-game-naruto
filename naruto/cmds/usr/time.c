/*  time.c */

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    seteuid(getuid());
    write("遊戲時間：" + NATURE_D->game_time() + "。\n");
    write("真實時間：" + CHINESE_D->chinese_date(time()) + "\n");
    write("火影忍者已經執行了" + CHINESE_D->chinese_period(uptime()) + "。\n");
    return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

這個指令讓你(妳)知道現在的時間。
HELP);
    return 1;
}
