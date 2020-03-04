// use.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string str, item;
    object ob;

    if( me->is_busy() ) return notify_fail("�A�{�b�S���šC\n");
    if( !arg || arg=="" ) return notify_fail("�A�n�ϥΤ���F��H\n");

    if( sscanf(arg, "%s to %s", item, str)  == 2 ) {
        ob = present(item, me);
        if( !ob ) ob = present(item, environment(me));
        if( !ob ) return notify_fail("�o�̨S���o�˪F��...\n");
    } else if( sscanf(arg, "%s on %s", item, str) == 2 ) {
        ob = present(item, me);
        if( !ob ) ob = present(item, environment(me));
        if( !ob ) return notify_fail("�o�̨S���o�˪F��...\n");
    } else {
        ob = present(arg, me);
        if( !ob ) ob = present(arg, environment(me));
        if( !ob ) return notify_fail("�o�̨S���o�˪F��...\n");
        str = "";
    }

    if( !function_exists("do_use", ob) )
       return notify_fail("�o�˪F����G����ϥΤ���...\n");

    ob->do_use(me, str);

    return 1;
}

int help()
{
    write(@TEXT
���O�榡�Guse <���~>

�o�ӫ��O�i�H���A�ϥίS���~�C
TEXT);
    return 1;
}
