/*  time.c */

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    seteuid(getuid());
    write("�C���ɶ��G" + NATURE_D->game_time() + "�C\n");
    write("�u��ɶ��G" + CHINESE_D->chinese_date(time()) + "\n");
    write("���v�Ԫ̤w�g����F" + CHINESE_D->chinese_period(uptime()) + "�C\n");
    return 1;
}

int help(object me)
{
     write(@HELP
���O�榡: time

�o�ӫ��O���A(�p)���D�{�b���ɶ��C
HELP);
    return 1;
}
