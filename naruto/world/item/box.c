#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"�w���_�c"NOR, ({ "happy box", "box" }));

    if( !clonep() ) {
        set("base_unit", "�c");
        set("base_value", 4000);
        set("base_weight", 10);
        set("no_box", 1);
        set("long", "�@�ӯ��_���_�c�A�A�Ԥ���Q���}(use)�ݸ̭�������C\n");
    }
    setup();
}

object do_random(string category)
{
    int rnd, *key;
    key = keys(ITEM_D->do_query_all(category));
    rnd = key[random(sizeof(key))];
    return ITEM_D->get_item(category, rnd);
}

int do_use(object me, string arg)
{
    object item, *inv;

    inv = all_inventory(this_player());

    switch( random(10000)+1 ) {
        case 101..300: item = do_random("wp"); break;   // 2%
        case 301..800: item = do_random("eq"); break;   // 5%
        case 801..2800: item = do_random("obj"); break; // 20%
        default: item = do_random("food"); break;       // 73%
    }
    if( !objectp(item) ) {
        tell_object(me, "�_�c�S��M�X�F�_�ӡC\n");
        return 1;
    }

    // �P�_���W���~�ƶq�A�]�����[�o��|�o�Ͷ}���쪫�~
    // �o�i�H�@���}���w�ֽc�W�[��bug
    if( sizeof(inv) >= 40 ) {
        tell_object(me, "�A���W�Ӧh�F��A�A�]�����ʤF�C\n");
        return 1;
    }

    // �}��L�k�}�쪺���~�A�|���v 1~5 �ӽc�l
    if( item->query("no_box") != 0 ) {
        int i = 1 + random(5);
        message_vision("$N������F���A���K�g�@�U���䪺���ˡA�K�N$n���F�}�ӡC\n", me, this_object());
        message_vision("���M�q$n���S���X�F"HIC"("+i+")"NOR"��$n...$N�W�i�������ߤF�_�ӡC\n", me, this_object());

        if( this_object()->query("keep_this") == 1 ) {
            this_object()->add_amount(i-1);
            this_object()->set("keep_this", 1);
        } else {
            this_object()->add_amount(i-1);
        }
        return 1;
    }

    // �Q�����~���v�S�}��A���v 1 �ӽc�l
    if( item->query("value") >= 150000 || item->query("base_value") >= 50000 ) {
        if( random(1000) > random(10) ) {
            message_vision("$N������F���A���K�g�@�U���䪺���ˡA�K�N$n���F�}�ӡC\n", me, this_object());
            message_vision("$N�o�{���Y�˵ۤ@��$n...\n", me, this_object());
            return 1;
        }
    }

    if( !item->move(me) ) {
        destruct(item);
        tell_object(me, "�A���W�Ӧh�F��A�A�]�����ʤF�C\n");
        return 1;
    }

    message_vision("$N������F���A���K�g�@�U���䪺���ˡA�K�N$n���F�}�ӡC\n", me, this_object());
    message_vision("$N�o�{���Y�˵ۤ@��$n...\n", me, item);

    // �Ӽƴ��
    this_object()->add_amount(-1);
    if( !this_object()->query_amount() )
        destruct(this_object());

    return 1;
}
