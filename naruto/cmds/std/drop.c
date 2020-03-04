// drop.c

#include <login.h>
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    object obj, *inv, obj2;
    int i, amount;
    string item;

    if( me->is_busy() )
        return notify_fail("�A�����ۨ�L�ơT\n");

    if(!arg) return notify_fail("�A�n��󤰻�F��S\n");
    if( !environment(me) ) return 0;

    if(sscanf(arg, "%d %s", amount, item)==2) {
        if( !objectp(obj = present(item, me)) )
            return notify_fail("�A���W�S���o�˪F��C\n");
        if( stringp(obj->query("no_drop")) || obj->query("keep_this") )
            return notify_fail("�o�ӪF��S��k���A�άO�w�gkeep�F...\n");
        if( !obj->query_amount() )
            return notify_fail( obj->name() + "����Q���}���C\n");
        if( amount < 1 )
            return notify_fail("�F�誺�ƶq�ܤ֬O�@�ӡC\n");
        if( amount > obj->query_amount() )
            return notify_fail("�A�S������h��" + obj->name() + "�C\n");
        else if( amount == (int)obj->query_amount() )
            return do_drop(me, obj);
        else {
            obj->set_amount( (int)obj->query_amount() - amount );
            seteuid(MUDLIB_UID);
            obj2 = new(base_name(obj));
            seteuid(getuid());
            obj2->set_amount(amount);
            return do_drop(me, obj2);
        }
    }

    if(arg=="all") {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
            do_drop(me, inv[i]);
        }
        write("Ok.\n");
        return 1;
    }

    if(!objectp(obj = present(arg, me)))
        return notify_fail("�A���W�S���o�˪F��C\n");
    return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
    mixed no_drop;

    if( no_drop = obj->query("no_drop") )
        return notify_fail( stringp(no_drop) ? no_drop : "�o�˪F�褣���H�N���C\n");

    if( obj->query("keep_this") ) 
    return notify_fail("�o�˪F��A�w�g keep �L�k���C\n");
    
    if( obj->query("equipped") )
    return notify_fail("�o�˪F��A�w�g�˳ƵۡA�L�k���C\n");

    if( environment(me)->is_area() ) {
        if( environment(me)->query("no_drop") ) {
            if( !function_exists("query_amount", obj) ) message_vision( "$N��U���@" + obj->query("unit") + "$n�Ƭ��@�}�����A�����b�o�̡C\n", me, obj);
            else message_vision( "$N��U��" + chinese_number(obj->query_amount()) + obj->query("unit") + "$n�Ƭ��@�}�����A�����b�o�̡C\n", me, obj);
            destruct(obj);
            return 1;
        }
        if( !area_move(environment(me), obj, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) return 0;
        } else if( !obj->move(environment(me)) ) return 0;

    // add log by -Acme-
    //  if( userp(me) ) log_file("static/DROP", sprintf("%s(%s) droped %s->%O\n", me->query("name"), me->query_id(), obj->query("name"), obj));

    if( obj->is_character() ) message_vision("$N�N$n�q�I�W��F�U�ӡM���b�a�W�C\n", me, obj);
    else {
        if( !function_exists("query_amount", obj) ) message_vision( "$N��U�@" + obj->query("unit") + "$n�C\n", me, obj);
        else message_vision( "$N��U" + chinese_number(obj->query_amount()) + obj->query("unit") + "$n�C\n", me, obj);

        if( !obj->query("value") && !obj->value() ) {
            write("�]���o�˪F��ä��ȿ��M�ҥH�H�̨ä��|�`�N�쥦���s�b�C\n");
            destruct(obj);
            return 1;
        }
    }
    // ���ȿ����F�覭�N�Q dest ���F... �o�̨S�� obj.... -elon 12/2/96
    if( obj ) obj->delete("keep_this");

    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡 : drop <���~�W��>
 
�o�ӫ��O�i�H���A��U�A����a�����~.
�Ҧp:
drop all��U�Ҧ��� keep �����~.
drop sword 2��U�A����a���ĤG�� sword.
drop 200 gold��U�G�ʨ����. 
HELP
    );
    return 1;
}
