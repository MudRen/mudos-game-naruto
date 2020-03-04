#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

void random_fly()
{
    object area;
    int i;
    string area_file = "/world/area/muye/muye.c";

    i = random(49);

    if( !objectp(area = load_object(area_file)) ) return 0;
    message_vision(CYN"$N�n���o�{�F����A�@�ȷϦa�N�����F�C\n"NOR, this_object());

    if( !area_move(area, this_object(), i, i) ) {
        message_vision(CYN"���O����@��$N�S�����N�N�a�X�{�b����C\n"NOR, this_object());
        return;
    }
    message_vision(CYN"�@�}�g���ӹL�A$N���M�X�{�b����C\n"NOR, this_object());
    return;
}
void create()
{
    set_name("�ۨӤ]", ({ "zi lai ye", "ye" }));
    set_race("human");
    set_level(80);
    set("camp", "muye");
    set("long", "�ǻ������T�Ԥ��@�A�]���۷�n��ҥH��H�s�٥L���n��P�H�A�A�i\n"
                "�H�ݨ�L��R���Ъ����G�]�����M��L�g�p���������n�a��F�C\n");

    set("title", "�T��");
    set("nickname", "�n��P�H");
    set("age", 52);
    set("gender", "male");
    
    // �@��ɰʧ@
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say ���������I�����I��B�}������I" :),
        (: random_fly :),
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    object item, pol;

    if( arg == "����" )  {
        do_chat(({
            (: command, "?" :),
            (: command, "say �M������O�ܯ��t���Ʊ��C" :),
            (: command, "say �o�i�O�����˼��Ѱ�u�򶰡v�����e�C" :),
            (: command, "say ���F�ڼs�j��Ū�̡A�]�u�n���F�I" :),
            (: command, "snicker" :),
        }));
        return;
    }
    if( arg == "��" )  {
        do_chat(({
            (: command, "stare " + this_player()->query("id") :),
            (: command, "say �椰��A�������X���A�R�N�n�F�C" :),
            (: command, "say ���M�ڲ{�b�����q���Ө���..." :),
            (: command, "say �p�G�֡u�����v�A�ڥi��|�Ҽ{�ݬ�..." :),
        }));
        return;
    }
    if( arg == "����" )  {
        if( objectp(pol = present("__POL__", this_player())) ) {
            message_vision("$N�ôb�a���D�G"HIG"���W�٦���߱o�S�n�����H�Ӥ��֮��өԡI\n"NOR, this_object());
            return;
        }
        do_chat(({
            (: command, "hmm" :),
            (: command, "say �J�M�o�ˡI�o�x��߱o�N�ɵ�" + this_player()->query("name") + "�ΡA���L�����u�Ѥ��i�C" :),
            (: command, "say �h��T�i���k���Ӥ����ڡI" :),
        }));

        pol = new(__DIR__"obj/pol.c");

        if( pol->move(this_player()) ) tell_object(this_player(), HIY"(�ۨӤ]���A�@�x" + pol->query("name") +"�C)\n"NOR);
        else {
            if( environment(this_player())->is_area() ) move_side(pol, this_player());
            else pol->move(environment(this_player()));
            tell_object(this_player(), HIY"(�ۨӤ]���A�@�x" + pol->query("name") + "�A���O�A���W�ӭ��A�u�n��b�a�W�C)\n"NOR);
        }
        this_player()->set_temp("picquest", 3);
        return;
    }
}
int give_check(object ob)
{
    if( ob->id("__PIC__") ) return 1;   // �Ӥ�
    else return 0;
}
int accept_object(object me, object ob)
{
    object item, book;

    if( is_busy() ) {
        do_chat((: command, "say �椰��IŲ�w���ήɶ��ܡI" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say ���ڻ����L�A�M��Ų�w�I" :));
        return 0;
    }
    if( !me->query_temp("picquest") ) {
        message_vision("$N���D�G"HIG"$n�S�ƧO�Ө�ê�ڤu�@�C\n"NOR, this_object(), me);
        return 0;
    }
    me->start_busy(3);
    this_object()->start_busy(5);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("picture/"+ob->query("id")) ) {
                message_vision("$N�ôb�a���D�G"HIG"�޳�$n...�o�i�Ӥ���~���L�ԡA�Q�V���N����C\n"NOR, this_object(), me);
                return 0;
            }
            switch( ob->query("pic") ) {
                case 0: message_vision("$N�ī�a�q�D�G"HIG""+me->query("name")+"�ڬO�n��˼��Ѱ󪺯����C�I�����F���Ӥ���ԣ�I\n"NOR, this_object(), me);
                        return 0;
                        break;
                case 1: message_vision("$N��}�}�a���D�G"HIG"�F��������"+me->query("name")+"�I�ܦ��ѥ���I���ڨ�Ų�wŲ�w...\n"NOR, this_object(), me);
                        break;
                case 2: message_vision("$N���D�G"HIG"�窺�O�ܫӮ��...���O�k�ʤ��n����Ų�w�C\n"NOR, this_object(), me);
                        return 0;
                        break;
                case 3: do_chat(({
                            (: command, "say ��..�ڬݬ�.." :),
                            (: command, "say �H�~�j�ԡH�n�D��..." :),
                            (: command, "angry" :),
                            (: command, "say �d����F����I���ڤk�ʷӤ��N�n�I" :),
                        }));
                        return 0;
                        break;
            }
            if( me->query_temp("picquest") == 1 ) {
                message_vision("\n\n$N�r�֦a���D�G"HIG"$n���F�ڳo��h���A�A���^�X�@�U�����L�h�C\n"NOR, this_object(), me);
                do_chat(({
                    (: command, "say ���˼��Ѱ��򶰪������ڦ��N��n�F�C" :),
                    (: command, "snicker" :),
                    (: command, "say �o�Ǹ�ƴN�����ӲĤT���Χa�I" :),
                    (: command, "say �o���s�����ڹw�����ĤG���N�e�A�������C" :),
                }));

                book = new(__DIR__"item/kiss_book2.c");

                if( book->move(me) ) tell_object(me, HIY"\n(�ۨӤ]�N"NOR+book->query("name")+NOR+HIY"�浹�F�A�C)\n\n"NOR);
                else {
                    if( environment(me)->is_area() ) move_side(book, me);
                    else book->move(environment(me));
                    tell_object(me, HIY"\n(�ۨӤ]�Q�N"NOR+book->query("name")+NOR+HIY"�浹�A�A���O�A���W�ӭ��A�u�n��b�a�W�C)\n\n"NOR);
                }
                // �����Ȧs�����
                me->delete_temp("picquest");
                me->delete_temp("picture");
            } else {
                do_chat( ({
                   (: command, "nod" :),
                   (: command, "say �o�i�窺�����I�~��V�O�a�I" :),
                   ( : destruct , ob : ),
                }) );
                me->set_temp("picture/"+ob->query("id"), 1);
                me->add_temp("picquest", -1);
            }
            break;
        default:
            do_chat((: command, "say ���O�Ӥ����ڷF�¡I" :));
            return 0;
            break;
    }
    return 1;
}
int accept_fight(object me)
{
    tell_object(me, HIY"(�ۨӤ]���b�M����������L���A���s�b�C)\n\n"NOR);
    return 0;
}
int accept_kill(object me)
{
    remove_all_killer();
    me->remove_killer(this_object());
    tell_object(me, HIY"(�ۨӤ]�M�`���M������S�ݨ�A�A���A�o�����ۥL�C)\n\n"NOR);
    return 1;
}
