/* eat.c */

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    int stuff;
    object ob;

    if( me->is_busy() ) return notify_fail("�A�{�b���b���A�S����...\n");

    if( !arg || arg=="" ) return notify_fail("�A�n�Y����S\n");

    ob = present(arg, me);
    if( !ob ) ob = present(arg, environment(me));
    if( !ob ) return notify_fail("�o�̨S���o�˪F��...\n");

    stuff = ob->query("food_stuff");
    if( !stuff ) {
        return notify_fail("�o�˪F�褣��Y...\n");
    }

    // �������Ī��A�ĪG�������A����b�԰����ϥ�
    if( ob->query("condition") && me->is_fighting() ) {
        return notify_fail("�A���b�԰��A�S��k�q�e���i��...\n");
    }

    if( !ob->stuff_ob(me) ) {
        return 1;
	}
	
    message_vision("$N�Y�U�F�@" + ob->query("unit") + "$n�C\n", me, ob);
    
    ob->add_amount(-1);
    if( ob->query_amount() <= 0 ) destruct(ob);

    return 1;
}

int help()
{
    write(@TEXT
���O�榡�Geat <����>

�o�ӫ��O�Ψ����A���H���i���ΪA���Ī��C
TEXT);
    return 1;
}
