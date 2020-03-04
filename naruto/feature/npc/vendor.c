/* vendor.c �ӤH */

#include <ansi.h>
#include <query.h>

mapping goods = ([]);

// �]�w�c�檺���~
void set_goods(int number, string type, int id, int amount, int value)
{
    goods[number] = ([]);
    goods[number]["type"] = type;
    goods[number]["id"] = id;
    goods[number]["amount"] = amount;
    goods[number]["amount_max"] = amount;
    goods[number]["value"] = value;
}

string do_list()
{
	int index, maximum;
	string msg;
    mapping record;

    if( (maximum=sizeof(goods)) <= 0 )
    	return this_object()->query("name") + "�ثe�S���c����󪫫~�C\n";

    msg  = "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += sprintf("�x%-68s�x\n", this_object()->query("name") + "�ثe���ӫ~�C��");
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n";
    msg += "�x�s��    �ƶq  ���/�Ȩ�  �W��                                       �x\n";
    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";

    for(index=1;index<=maximum;index++) {
        if( undefinedp(goods[index]) ) continue;
        switch( goods[index]["type"] ) {
            case "eq":   record = ITEM_D->do_query("eq", goods[index]["id"]); break;
            case "wp":   record = ITEM_D->do_query("wp", goods[index]["id"]); break;
            case "food": record = ITEM_D->do_query("food", goods[index]["id"]); break;
            case "obj": record = ITEM_D->do_query("obj", goods[index]["id"]); break;
            default: continue;
        }
        if( !mapp(record) ) continue;

        msg += sprintf("�x%4d %7s %10d  %-s\n", 
                       index,
                       ( goods[index]["amount_max"] == -1 ? "oo" : "" + goods[index]["amount"] ),
                       goods[index]["value"] < record["value"] ? record["value"] : goods[index]["value"],
                       record["name"] );
    }

    msg += "�u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    msg += "�x��J help trade �A�Ѧp��ϥΥ�����O�C                              �x\n";
    msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��";

    return msg;
}

int to_sell(object who, int number, int amount)
{
    int value;
    object item;
    mapping record;

    if( !objectp(who) ) return 0;

    if( sizeof(all_inventory(who)) >= 40 ) {
        tell_object(who, "���a�o�{�A���G�����ʳo�˰ӫ~�A�K����A�F�C\n");
        return 1;
    }

    if( who->query_encumbrance() >= who->query_ability("carriage") ) {
        tell_object(who, "���a�o�{�A���G�����ʳo�˰ӫ~�A�K����A�F�C\n");
        return 1;
    }

    if( amount <= 0 ) {
        tell_object(who, "�A�Q�n�R�X�Ӱӫ~�H\n");
        return 1;
    }

    if( amount > 999 ) {
        tell_object(who, "�@���̦h�u���ʶR999�Ӱӫ~...\n");
        return 1;
    }
    // �S���o�Ӱӫ~�s��
    if( undefinedp(goods[number]) ) {
        tell_object(who, "�S���o�Ӱӫ~�s���C\n");
        return 1;
    }

    // �D�L���q�������ӫ~���ƶq�ˬd
    if( !amount ) amount = 1;
    if( goods[number]["amount_max"] != -1 && goods[number]["amount"] < amount ) {
        tell_object(who, "�o�Ӱӫ~�ƶq�S���o��h�C\n");
        return 1;
    }

    switch( goods[number]["type"] ) {
        case "eq":   record = ITEM_D->do_query("eq", goods[number]["id"]); break;
        case "wp":   record = ITEM_D->do_query("wp", goods[number]["id"]); break;
        case "food": record = ITEM_D->do_query("food", goods[number]["id"]); break;
        case "obj": record = ITEM_D->do_query("obj", goods[number]["id"]); break;
        default:
            tell_object(who, "���a�o�{�o�Ӱӫ~�����D���H�Y�U�[�F�A�A�L�k�ʶR�C\n");
            // �γ\�ɮפw�g���s�b�A�q�C���R��
            map_delete(goods, number);
            return 1;
    }
    if( !mapp(record) ) {
        tell_object(who, "���a�o�{�o�Ӱӫ~�����D���H�Y�U�[�F�A�A�L�k�ʶR�C\n");
        // �γ\�ɮפw�g���s�b�A�q�C���R��
        map_delete(goods, number);
        return 1;
    }

    if( goods[number]["value"] < record["value"] ) value = record["value"];
    else value = goods[number]["value"];

    value = value * amount;

    // �Ȧ������
    if( who->query("bank") < value ) {
        tell_object(who, "�A�Ȧ�̪��������A�L�k�ʶR���ӫ~�C\n");
        return 1;
    }

    // �L�k�إ߸Ӱӫ~
    if( !objectp(item = new(record["file_name"])) ) {
        tell_object(who, "���a�o�{�o�Ӱӫ~�����D���H�Y�U�[�F�A�A�L�k�ʶR�C\n");
        // �γ\�ɮפw�g���s�b�A�q�C���R��
        map_delete(goods, number);
        return 1;
    }
    
    if( !function_exists("set_amount", item) && amount > 1) {
        tell_object(who, "�o�ӪF��@���u��R�@�ӡC\n");
        destruct(item);
        return 1;
    }

    item->set_amount(amount);
    
    if( !item->move(who) ) {
        tell_object(who, "���a�o�{�A���G�����ʳo�˰ӫ~�A�K����A�F�C\n");
        // �R�����~
        destruct(item);
        return 1;
    }

    message_vision("$N��F" + chinese_number(value) + "��Ȥl�V" + this_object()->query("name") + "�R�U" +
                   chinese_number(amount) + "��" + record["name"] + "�C\n", who);

    // �q�Ȧ榩��
    who->add("bank", -value);

    // �D�L���q�������ӫ~�ƶq�ݧ���
    if( goods[number]["amount_max"] != -1 )
        goods[number]["amount"] -= amount;

    return 1;
}

// ��_�ӫ~���ƶq
void reset()
{
	int index, maximum;
	maximum = sizeof(goods);
    for(index=1;index<=maximum;index++) {
        if( undefinedp(goods[index]) ) continue;
        goods[index]["amount"] = goods[index]["amount_max"];
    }
}
