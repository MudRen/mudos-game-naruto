#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string str1, str2, type, *kk;
    object book, eq;
    mapping effect;

    if( me->is_busy() ) return notify_fail("�A�{�b�S���šC\n");
    if( !arg || arg=="" ) return notify_fail("���O�榡�Gcombine <���b> with <�Z��/����>\n");

    if( sscanf(arg, "%s with %s", str1, str2) != 2 ) 
        return notify_fail("���O�榡�Gcombine <���b> with <�Z��/����>\n");

    book = present(str1, me);
    if( !book ) return notify_fail("�A���W�S���o�ب��b...\n");

    if( !mapp(effect = book->query("effect")) )
        return notify_fail("�o�Ӥ��O�Ψӱj�Ƹ˳ƪ����b...\n");

    eq = present(str2, me);
    if( !eq ) return notify_fail("�A���W�S���o�ظ˳�...\n");

    if( eq->query("no_combine") >= 1 ) 
        return notify_fail("�o�˪��~����i��j�ơC\n");

    if( eq->query("equipped") ) 
        return notify_fail("�A��������o�Ӹ˳ƨ����~��i��j�ơC\n");

    switch( effect["type"] ) {
        case "EQ":
            if( !eq->is_armor() ) return notify_fail("�����u��ϥΦb����W���C\n");
            if( eq->query("changed") >= 3 ) return notify_fail("�o�󨾨�w�g�L�k�ϥΥ�����b�F�C\n");

            message_vision(HIW"$N�N $n "HIW"��b��U���ۥB�L�̰�ᦳ��A����J�ä�...\n"NOR, me, book);
            
            destruct(book);

            eq->add("changed", 1);

            // ���]���v
            if( random(100) >= effect["success"] ) {
                message_vision("�n������Ʊ��]�S�o��...\n", me);
                return 1;
            } else message_vision(HIY"���� $N "HIY"���X�C�m���~�A�{�{�ʤH...\n"NOR, eq);

            eq->add("success", 1);
            eq->set("apply_armor", eq->query("apply_armor") );

            if( sscanf(eq->query("name"), "%s %s", str1, str2) == 2 ) {
                eq->set("name", HIY"(+" + eq->query("success") + ") "NOR + str2 );
            } else eq->set("name", HIY"(+" + eq->query("success") + ") "NOR + eq->query("name") );

            type = eq->query("wear_as");

            foreach( str1 in keys(effect) ) {
                if( str1 == "type" || str1 == "success" ) continue;
                eq->add("apply_armor/" + type + "/" + str1, effect[str1]);
            }

            break;
        case "WP":
            if( !eq->is_weapon() ) return notify_fail("�Z���u��ϥΦb�Z���W���C\n");
            if( eq->query("changed") >= 10 ) return notify_fail("�o��Z���w�g�L�k�ϥΥ�����b�F�C\n");

            message_vision(HIW"$N�N $n "HIW"��b��U���ۥB�L�̰�ᦳ��A����J�ä�...\n"NOR, me, book);
            
            destruct(book);

            eq->add("changed", 1);

            // ���]���v
            if( random(100) >= effect["success"] ) {
                message_vision("�n������Ʊ��]�S�o��...\n", me);
                return 1;
            } else message_vision(HIY"���� $N "HIY"���X�C�m���~�A�{�{�ʤH...\n"NOR, eq);

            eq->add("success", 1);

            if( sscanf(eq->query("name"), "%s %s", str1, str2) == 2 ) {
                eq->set("name", HIY"(+" + eq->query("success") + ") "NOR + str2 );
            } else eq->set("name", HIY"(+" + eq->query("success") + ") "NOR + eq->query("name") );

            eq->set("apply_weapon", eq->query("apply_weapon") );

            kk = eq->query("wield_as");
            foreach( str1 in kk ) {
                foreach( str2 in keys(effect) ) {
                    if( str2 == "type" || str2 == "success" ) continue;
                    eq->add("apply_weapon/" + str1 + "/" + str2, effect[str2]);
                }
            }

            break;
        default:
            return notify_fail("�o�Ө��b�����D�A�ݨӵL�k�ϥ�...\n");
            break;
    }

    if( objectp(eq=find_object(base_name(eq))) ) destruct(eq);
    return 1;
}

int help()
{
    write(@TEXT
���O�榡�Gcombine <���b> with <�Z��/����>

�o�ӫ��O�i�H�Q�Ψ��b�ӱj�ƧA���Z���Ψ���C
TEXT);
    return 1;
}
