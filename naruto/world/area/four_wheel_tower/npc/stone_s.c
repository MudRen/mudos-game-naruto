#include <npc.h>
#include <ansi.h>

void do_startDamage()
{
    int i, j, size;
    object room, area;
    object *inv;
    string file, msg, *pattern;

    file = base_name(environment(this_object())) + ".c";
    pattern = AREA_PATTERN_D->getPatterns();
    room = load_object(file);

    inv = all_inventory(room);
    size = sizeof(inv);

    if( !query("change_map") ) return;

    // �ǽT���P�_ pattern �����ӽs��
    for(j=0;j<sizeof(pattern);j++) {
        if( pattern[j] == "/world/area_pattern/mist900_s_02.c" ) break;
    }
    for(i=0; i<size; i++) {
        if( !userp(inv[i]) ) continue;

        // �p�G�b���|���ܪ���m�w�I���A�������ʤ@�U���A�|�׹L�ݵ���
        // �ҥH���I�]���P�@��m�A���ަb���Ӥ������I���@�� +1
        if( (inv[i]->query("area_info/x_axis") >= 14 && inv[i]->query("area_info/x_axis") <= 16) 
            && (inv[i]->query("area_info/y_axis") >= 14 && inv[i]->query("area_info/y_axis") <= 18) ) {

            msg = environment(this_object())->query("name")+"x15y15";
        } else {
            msg = environment(this_object())->query("name")+"x"+inv[i]->query("area_info/x_axis")+"y"+inv[i]->query("area_info/y_axis");
        }

        AREA_PATTERN_D->setPattern(this_object(), j);

        // �P�_���a�O�_�w�I����...
        // ����Y���a�ήɷ|�����a�@�� temp ������m
        // �T�����b�P�@�Ӧ�m�N�Ǧ^ recall
        if( inv[i]->query_temp("tower_recall/"+msg) ) {
            inv[i]->add_temp("tower_recall/"+msg, 1);
            if( inv[i]->query_temp("tower_recall/"+msg) >= 3 ) {
                if( inv[i]->is_busy() ) {
                    inv[i]->interrupt(inv[i], "*unconcious");
                    inv[i]->clear_condition();
                }
                if( !inv[i]->move("/world/area/wizard/guildhall.c") ) {
                    inv[i]->start_busy(1);
                } else {
                    message_vision(HIW"�@�}�ե��L�h�A$N�u�����v�@�n�A��M�q�ѪŤ����F�U�F�A�^�F�Ӫ��Y�ˡC\n"NOR, inv[i]);
                    inv[i]->delete_temp("tower_recall");
                    inv[i]->set_stat_current("ap", 1);
                    inv[i]->set_stat_current("hp", 1);
                    inv[i]->set_stat_current("mp", 1);
                }
            }
        } else {
            inv[i]->delete_temp("tower_recall");
            inv[i]->set_temp("tower_recall/"+msg, 1);
        }
        message_vision("$N"HIY"�@�}�n�̫��X�j�q�����I�|�P����v���ܤ�...\n"NOR, this_object());
        return;
    }
    delete("change_map");
    return;
}

void create()
{
    set_name(HIW"��F��"NOR, ({ "stone", "sand" }) );
    set("channel_id", HIW"��F��"NOR);
    set_level(1);
    set_race("human");
    set("age", 1);
    set("long", "�զ⪺���j���Y�A�n����o�����Ҫ��F�Ƨ��������v�T�A���ʦp�s�C\n"
                "�����ٷ|�o�X���⪺�{���A���O���Y���o���M�O���զ�C\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: do_startDamage :),
    }));
    setup();
}

// �P�_���a�O�_�X�{
void init()
{
    if( query("change_map") ) return;

    if( userp(this_player()) ) set("change_map", 1);
    else return;
}

// ����fight
int accept_fight(object me, string arg)
{
    return 0;
}

// ���� kill
int accept_kill(object me, string arg)
{
    remove_all_killer();
    me->remove_killer(this_object());
    return 1;
}
