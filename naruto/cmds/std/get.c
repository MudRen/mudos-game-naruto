/* get.c
   ���O�G �B��
   create by Acme
*/

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int isCombined(object item)
{
    if( !objectp(item) ) return 0;
    if( !function_exists("query_amount", item) ) return 0;
    return 1;
}

object doGetFrom(object me, string from)
{
    object ofrom;
    ofrom = present(from, me);
    
    if( !objectp(ofrom) ) ofrom = present(from, environment(me));
    if( !objectp(ofrom) ) {
        tell_object(me, "�A����S�� " + from + " �o�˪F��C\n");
        return 0;
    }

    if( (living(ofrom) || userp(ofrom)) ) {
        if( !wizardp(me) ) {
            tell_object(me, "�A�S��k�o�򰵡C\n");
            return 0;
        } else {
            if( wiz_level(me) <= wiz_level(ofrom) ) {
                tell_object(me, "�A���Ův���ť������谪�A�~��j���C\n");
                return 0;
            }
        }
    }
    return ofrom;
}

object doGetItem(object me, object from, string sitem, int amount)
{
    object item;

    // �ˬd���~�O�_�s�b
    if( !objectp(item = present(sitem, from)) ) {
        if( from == environment(me) )
            tell_object(me, "�A����S���o�˪F��C\n");
        else if( from->is_character() )
            tell_object(me, from->name() + "���W�S���o�˪F��C\n");
        else tell_object(me, from->name() + "�̭��S���o�˪F��C\n");
        return 0;
    }

    if( (living(item) || userp(item)) || item->is_corpse() ) {
    tell_object(me, "�A����o�˰��C\n");
        return 0;
    }

    if( isCombined(item) ) {  // �ƦX�����~
    if( amount == 0 ) amount = item->query_amount();

        if( amount < 1 || amount > item->query_amount() ) {
            if( from == environment(me) ) tell_object(me, "�A����S���o��h�ƶq��" + item->name() + "�C");
            else if( from->is_character() ) tell_object(me, from->name() + "���W�S���o��h�ƶq��" + item->name() + "�C");
            else tell_object(me, from->name() + "�̭��S���o��h�ƶq��" + item->name() + "�C");
            return 0;
        }

        if( amount == item->query_amount() ) // �������ƶq��n�@��
            return item;
        else {                               // �������ƶq���@��
            // �i�����
            object new_item;
            new_item = new(base_name(item));
            new_item->set_amount(amount);
            item->add_amount(-amount);
            return new_item;
        }

    } else return item;                 // �D�ƦX�����~
}

int doGet(object me, object from, object item)
{
    int amount;
    string msg;
    object *guard, *obj;

    if( !objectp(me) || !objectp(from) || !objectp(item) ) {
        tell_object(me, "�A�S����k������F��C\n");
        return 0;
    }
    
    if( item->query("no_get") ) {
        tell_object(me, "�A�L�k�����o�˪F��C\n");
        return 0;
    }
    
    if( guard = item->query_temp("guarded") ) {
        guard = filter_array(guard, (: objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2) :), me);
        if( sizeof(guard) ) return notify_fail( guard[0]->name() + "���u�b" + item->name() + "�@�ǡM�������H�����C\n");
    }
    
    if( me->over_encumbranced() ) {
        tell_object(me, "�A�w�g�t���L���F�C\n");
        return 0;
    }
    obj = all_inventory(me);

    if( sizeof(obj) >= 40 ) {
        tell_object(me, "�A���W�����~�w�g�W�L��a�W���F�C\n");
        return 0;
    }
    amount = item->query_amount();

    if( !item->move(me) ) {
        tell_object(me, "�A�L�k�����o�˪F��C\n");
        // ���^��Ӫ��a�I(�]�����i��g�L����
        if( from->is_area() ) move_side(item, me);
        else item->move(from);
        return 0;
    }
    msg = "$N";

    if( from == environment(me) ) {
        msg += "�߰_";
    } else {
        if( from->is_character() ) {
            msg += "�q" + from->name() + "���W";
            if( item->query("equipped") ) msg += "���U";
            else msg += "�j�X";
        } else msg += "�q" + from->name() + "�����X";
    }
    
    if( isCombined(item) ) msg += chinese_number(amount);
    else msg += "�@";

    msg += item->query("unit") + "$n�C\n";

    message_vision(msg, me, item);

    return 1;
}

int doGetAll(object me, object from)
{
    object item, *inv;

    if( me->is_fighting() ) {
        tell_object(me, "�A�{�b�S�Ť@�����o��h�F��C\n");
        return 0;
    }

    // ���o���Ҥ��Ҧ�����
    if( from->is_area() ) {
        mapping info;
        if( (info = me->query("area_info")) )
        inv = from->query_inventory(info["x_axis"], info["y_axis"]);
    } else inv = all_inventory(from);

    foreach(item in inv) {    
        if( item->query("no_get") ) continue;
        if( (living(item) || userp(item)) ) continue;
        if( me->over_encumbranced() ) break;
        doGet(me, from, item);
    }

    tell_object(me, "ok.\n");
    return 1;
}

int main(object me, string arg)
{
    int amount = 0;
    string item, from;
    object oitem, ofrom;

    if( !arg ) return notify_fail("�A�n������F��H\n");
    if( me->is_busy() ) return notify_fail("�A�{�b�٨S���Ů��F��C\n");
    
    // �q�Y�Ӫ��~�̭����X�ƭӪF��
    if( sscanf(arg, "%d %s from %s", amount, item, from) == 3 ) {
        if( !(ofrom = doGetFrom(me, from)) ) return 1;

    // �q�Y�Ӫ��~�̭����X�F��
    } else if( sscanf(arg, "%s from %s", item, from) == 2 ) {
    if( !(ofrom = doGetFrom(me, from)) ) return 1;
    if( item == "all" ) {
        doGetAll(me, ofrom);
        return 1;
    }

    // �q���Ҥ�����
    } else if( sscanf(arg, "%d %s", amount, item) == 2 ) {
        ofrom = environment(me);
    } else {
        item = arg;
        ofrom = environment(me);
        if( item == "all" ) {
            doGetAll(me, ofrom);
            return 1;
        }
    }
    if( !(oitem = doGetItem(me, ofrom, item, amount) ) ) return 1;
    if( !doGet(me, ofrom, oitem) ) return 1;

    if( me->is_fighting() ) me->start_busy(1);

    return 1;
}

int help(object me)
{
    write(@HELP
���O�榡 : get <���~�W��> [from <�e���W>]

�o�ӫ��O�i�H���A�߰_�a�W�ήe�������Y�˪��~�C
�Y���~�W�ٿ�J�� all ��ܭn�����Ҧ��F��
HELP
    );

return 1;
}
