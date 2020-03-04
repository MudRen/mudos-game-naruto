#include <npc.h>
#include <ansi.h>

void do_clone()
{
    object enemy, item;
    // �S���ĤH
    enemy = this_object()->query_opponent();
    item = new(__DIR__"item/r_dice.c");
    if( !enemy ) return;
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/psychical") == 1) {
    return;
    }
    this_object()->add_temp("quest/psychical", 1);
    message_vision("$N�E�����W���O�A�C�C��{�ƥX�@��"HIW"���I��l"NOR"�I\n", this_object(), enemy);
    item->move(this_object());
    call_out("rolldice_1",5,this_object(),enemy);
    return;
}
void rolldice_1()
{
    int damage;
    object enemy;
    enemy = this_object()->query_opponent();
    // �S���ĤH
    this_object()->delete_temp("quest/psychical");
    if( !enemy ) {
        do_chat(({ 
            (: command, "drop dice" :),
        }));
        return;
    }
    // �ĤH�b���P��m
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy)) {
            do_chat(({ 
                (: command, "drop dice" :),
            }));
            return;
        }
    } else {
        if( environment(enemy) != environment(this_object()) ) {
            do_chat(({ 
                (: command, "drop dice" :),
            }));
            return;
        }
    }
    do_chat(({ 
        (: command, "roll dice" :),
    }));
    return;
}
void create()
{
    set_name("��k", ({ "dice man", "man" }));
    set_race("human");
    set_level(35);
    set("title",HIW"���밪��"NOR);
    set("age", 20);
    set("long", "����g�H�A�s���W��A���O��l�I�ơC\n");
    set("chat_chance", 10);
    set("chat_msg", ({
       (: command, "say �����쪱�@��ܡH" :),
       CYN"��k�q�h�����X��l�⪱�ۡC\n"NOR,
       CYN"��k�N��l�¦a�W�@��A���G�O��"HIY"�j�N"NOR+CYN"�C\n"NOR,
    }) );
    // �԰��ʧ@
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_clone :),
        (: command, "grin" :),
    }) );
    setup();
    set_stat_current("hp", 9999);             // ��O
    set_stat_maximum("hp", 9999);             // �̤j��
}
int give_check(object ob)
{
    if( ob->id("_BANDIT_CARD_") ) return 1;           // ���ⶱ�Υd
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say ���u�����I" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �S�ݨ�ڦb���[�ܡI" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( ob->query_amount() > 1 ) {
                do_chat((: command, "say �u�n���ڤ@�i�N���F�C" :));
                return 0;
            }
            message_vision("$N�N���ۻ��D�R"HIG"��ڴN���H�F�I\n"NOR, this_object());
            do_chat(({ 
               (: command, "follow " + this_player()->query("id") :),
               (: command, "guard " + this_player()->query("id") :),
               ( : destruct , ob : )
            }));
            break;
        default:
            do_chat((: command, "say �ڤ��ݭn�o�˪F��C" :));
            return 0;
            break;
    }
    return 1;
}
void die()
{
    object ob, *obs;
    obs = all_inventory(this_object());
    if( this_object()->query_temp("quest/psychical") == 1 ||
        this_object()->query_temp("quest/rolldice") == 1) {

        message_vision("�]��$N�����ҥH"HIW"���I��l"NOR"���������F...�C\n"NOR, this_object());
        this_object()->delete_temp("quest/psychical");
        foreach( ob in obs ) destruct(ob);
    }
    ::die();
}
