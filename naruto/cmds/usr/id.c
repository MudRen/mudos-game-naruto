/* id.c */

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i, j;
    object obj, *inv;
    string *id;

    if( !arg ) {
        inv = all_inventory(me);
        if( !sizeof(inv) ) return notify_fail("�A���W�S������F��C\n");
        write( "�A(�p)���W��a���~���O�٦p�U(�k��) :\n");
        for(i=0; i<sizeof(inv); i++) {
            if( !inv[i]->visible(me) ) continue;
            printf("%-20s = %s\n", inv[i]->name(),
            implode(inv[i]->parse_command_id_list(), ", ") );
        }
        return 1;
    }

    if( arg=="here" ) {
        if( environment(me)->is_area() ) {
            mapping info;
            info = me->query("area_info");
            inv = environment(me)->query_inventory(info["x_axis"], info["y_axis"]);
        } else inv = all_inventory(environment(me));
        if( !sizeof(inv) ) return notify_fail("�o�̨S������F��C\n");
        write( "�b�o�өж���, �ͪ��Ϊ��~��(�^��)�W�٦p�U :\n");
        for(i=0; i<sizeof(inv); i++) {
            if( !inv[i]->visible(me) ) continue;
            printf("%-20s = %s\n", inv[i]->name(),
            implode(inv[i]->parse_command_id_list(), ", ") );
        }
        return 1;
    }
}

int help(object me)
{
    write(@HELP
���O�榡 : id [here]
 
�o�ӫ��O�i�H���A���D���~���^��W�٤ΦW�r. �u�� id �|���
�A���W����a���~���W��. 'id here' �h��ܩҦ���A�b�P�@��
���Ҹ̪�����W��.
HELP
    );
    return 1;
}