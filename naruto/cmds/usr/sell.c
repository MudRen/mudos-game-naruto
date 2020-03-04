/* sell.c by -Acme-
*/

inherit F_CLEAN_UP;

private void create() { seteuid(getuid()); }

int sell_item(object item)
{
	int value;
    string name;

    if( item->query("money_id") )
        return notify_fail("�A�n��u���v�S\n");

    if( item->query("no_sell") )
        return notify_fail("�o�˪F�褣���C\n");

    if( (value = item->query("value")) <=0 )
        return notify_fail("�o�˪F�褣�ȿ��C\n");

    if( item->query("keep_this") )
    	return notify_fail("�o�˪F��A�w�g keep �L�k�c��C\n");
    
    if( item->query("equipped") )
        return notify_fail("�o�˪F��A�w�g�˳ƵۡA�L�k�c��C\n");

    value /= 2;

    name = ( item->query_amount() ? chinese_number(item->query_amount()) : "�@" );
    name += ( item->query("base_unit") ? item->query("base_unit") : 
            ( item->query("unit") ? item->query("unit") : "��" ) );
    name += item->query("name");

    if( !environment(this_player())->to_stock(item) )
    	return notify_fail("���E���G���@���U�o�˪��~�C\n");

    message_vision("$N�H" + chinese_number(value) + "��Ȥl�������N" + name + "��X�h�C\n", this_player() );
    
    // �����N���[��Ȧ��
    this_player()->add("bank", value);

    return 1;
}

int main(object me, string arg)
{
	int amount;
	object item;

	if( !environment(me) )
	    return notify_fail("�A�{�b���B�b���A�������D�F�I\n");
	if( !environment(me)->is_hockshop() )
	    return notify_fail("�A�u��b���E��F��C\n");
    if( me->is_busy() )
        return notify_fail("�A�{�b�S���šI\n");
    if( !arg )
    	return notify_fail("�A�Q�椰��F��H\n");
    
    if( arg == "all" ) {
        object *inv;
        
        inv = all_inventory(this_player());
        foreach(item in inv) {
            if( !item ) continue;
            sell_item(item);
        }
        write("Ok�C\n");
        return 1;
    }

    if( sscanf(arg, "%d %s", amount, arg) == 2 ) {
    	object new_item;
    	if( !(item = present(arg, me)) )
    		return notify_fail("�A�Q�n���_���򪫫~�H\n");
    	if( amount <= 0 ) 
    		return notify_fail("�A�Q�n��X�Ӫ��~�H\n");
    	if( item->query_amount() < amount )
    		return notify_fail("�A���W�S���o��h��" + item->query("name") + "�C\n");
    	
    	// �ۦP�ƶq
    	if( amount == item->query_amount() )
    		return sell_item(item);
    	
    	if( !objectp(new_item = new(base_name(item))) )
    		return notify_fail("�A���G�L�k�c��o�˪��~�C\n");
    	
    	new_item->set_amount(amount);
    	item->add_amount(-amount);
    	
    	// �L�k��X�A�hdest new_item, �ñN�쥻��item amount��_
    	if( !sell_item(new_item) ) {
    		destruct(new_item);
    		item->add_amount(amount);
    	}
    	
    	return 1;
    }

    if( !(item = present(arg, me)) )
        return notify_fail("�A�Q�n���_���򪫫~�H\n");

    return sell_item(item);
}

int help(object me)
{
  write(@HELP
���O�榡 : sell [�ƶq] ���~

�o�i���O�i�H�N�A���W�����~��X�h�A�q�`�u���b���E���a��~���
�c�檫�~�C�ҡG

sell blade     �N���W���Ĥ@��M��X�h
sell blade 2   �N���W���ĤG��M��X�h
sell 3 pill    �N���W��pill��X�T�ӡA�q�`�Ω�u�ƦX���~�v�W
sell 4 pill 2  �N���W�ĤG�諸pill��X�|��

�������O�G list, buy
HELP);
    return 1;
}
