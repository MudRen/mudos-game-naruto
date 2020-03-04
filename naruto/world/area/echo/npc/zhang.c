#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("�ѱi", ({ "old zhang", "zhang" }) );
    set_race("human");
    set_level(50);
    set("long",@LONG
�L�O�@��߱��ܮt���ѱi�A�]�Oı�o�ͬ����{�򪺦ѱi�A���ѽ�F�X
�Q�~�A���F�Ĥ@�ԥH�����ѥ��ѡu�@�֡v���ѩ��ѪO��o�y�ѯ��١z
��A���ۤQ�X�~�C�~���D�ԥ��ѡC�o���S�D�{���ܡA�ϥL�q�������@
��ݰ_�ӫD�`�Z�o���H�A�����Q���L���g�O�ѩ�����C
LONG);
    set("title",HIY"������Ѫ�"NOR);
    set("age", 50);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
       (: command, "sigh" :),
       (: command, "say �֯�ϱϧڪ��k����I" :),
       (: command, "cry" :),
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "������" ) {
        do_chat( ({
            (: command, "shake" :),
            (: command, "say �ڤk��Q�D�H��F�C" :),
            (: command, "say �{�b�S�߱��N�����ѡC" :),
        }) );
        return;
    }
    if( arg == "�D�H" || arg == "�����~" ) {
        do_chat( ({
            (: command, "scream" :),
            (: command, "say �e�̧�F�ڤk��I" :),
            (: command, "say �֯�ϱϧڪ��I" :),
        }) );
        return;
    }
    if( arg == "�k��" ) {
        do_chat( ({
            (: command, "sigh" :),
            (: command, "say �ڤk��Q���ǥi�c���D�H��h�F�C" :),
            (: command, "say ��ɧ��H���Q�����F�A�ѧکM�ڤk���H�C" :),
            (: command, "say �ڤk��n�D�e�̩�L�ڡA�o�N��e�̦^�h�C" :),
            (: command, "slap zhang" :),
            (: command, "say �ګ�򨺻�S�ΩO�I" :),
        }) );
        return;
    }
    if( arg == "�ϧA" || arg == "��" ) {
        if( query_temp("that's_ok") >= 1) {
            tell_object(this_player(),HIY"�ѱi�������ۥ��]����A�S�ɶ��z�A�C\n"NOR);
            return;
        }
        if( this_player()->query_temp("quest/help_girl") == 1) {
            do_chat((: command, "say �ɶ��򭢡I���֥h���I" :));
            return;
        }
        this_player()->add_temp("quest/help_girl", 1);
        do_chat( ({
            (: command, "dance" :),
            (: command, "say �@���N���U�A�F�I" :),
            (: command, "say �֥h�֦^��I" :),
            (: command, "say �D�H����m�N�h�j���ݰ��a�I" :),
        }) );
        return;
    }
    if( arg == "����" ) {
        if( this_player()->query_temp("quest/help_girl") == 1) {
            this_player()->delete_temp("quest/help_girl");
            do_chat( ({
                (: command, "hammer " + this_player()->query("id") :),
                (: command, "say ���O�ڪ��ɶ����I" :),
            }) );
            return;
        }
        do_chat( ({
            (: command, "?" :),
            (: command, "say ���Ϥ���I�O��ڶ}�����I" :),
        }) );
        return;
    }
}
void init()
{
    object item;
    int i;
    if( this_player()->id("_HELP_GIRL_") ) {
        i = random(100);
        set_temp("that's_ok", 1);
        message_vision(HIY"\n$N�@����$n�K�������a��$n���}�F�A�s���³��ѤF���C\n"NOR, this_object(), this_player());
        if( i >= 50) {
            if( file_size("/world/drug/noodle2.c") < 0 ) return 0;
            if( catch(item = new("/world/drug/noodle2.c")) ) return 0;
            if( item->move(environment(this_object())) ) {
                message_vision(HIC"\n�b�a�W�d�U�@�J$N���]�ѤF�a����"+item->name()+"�C\n\n"NOR, this_object(), this_player());
            } else {
                destruct(item);
                return 0;
            }
        } else
        if( i >= 25 && i <= 49 ) {
            if( file_size(__DIR__"item/noodle.c") < 0 ) return 0;
            if( catch(item = new(__DIR__"item/noodle.c")) ) return 0;
            if( item->move(environment(this_object())) ) {
                message_vision(HIC"\n�b�a�W�d�U�@�J$N���]�ѤF�a����"+item->name()+"�C\n\n"NOR, this_object(), this_player());
            } else {
                destruct(item);
                return 0;
            }
        } else
        if( i >= 2 && i <= 24 ) {
            if( file_size("/world/area/muye/npc/item/noodle.c") < 0 ) return 0;
            if( catch(item = new("/world/area/muye/npc/item/noodle.c")) ) return 0;
            if( item->move(environment(this_object())) ) {
                message_vision(HIC"\n�b�a�W�d�U�@�J$N���]�ѤF�a����"+item->name()+"�C\n\n"NOR, this_object(), this_player());
            } else {
                destruct(item);
                return 0;
            }
        } else {
            if( file_size(__DIR__"eq/ring.c") < 0 ) return 0;
            if( catch(item = new(__DIR__"eq/ring.c")) ) return 0;
            if( item->move(environment(this_object())) ) {
                message_vision(HIW"\n�b�a�W�d�U�@�T�{�{�o����"NOR+item->name()+HIY"�C\n\n"NOR, this_object(), this_player());
            } else {
                destruct(item);
                return 0;
            }
        }
        destruct(this_player());
        do_chat((: destruct, this_object() :));  // ����A�����~������b�a�W
    }
}
