#include <npc.h>
#define CATEGORY    "level_e"
#define ID          2

inherit F_VILLAGER;

void create()
{
    set_name("�N�Фp�j", ({ "ji tian", "tian" }));
    set_race("human");
    set_level(5);
    
    set("long", "�N�Фp�j���o�եխD�D���A�����b������b�����Ө��h�C\n");
    set("camp", "muye");
    set("age", 23);
    set("gender", "female");
    
    // �@��ɰʧ@
    set("chat_chance", 1);
    set("chat_msg", ({
        (: command, "say �����F�I�����F�I" :),
    }) );

    setup();
}

/* �Ȯɥ������O
// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "����" || arg == "�Ȫ�" || arg == "�����Ȫ�") {
        if( me->query_score("elevel") >= 100 ) {
            tell_object(me, "�N�Фp�j���G���ӷQ�z�A�C\n");
            return 0;
         }
        if( !me->query_quest(CATEGORY, ID) ) {
            object pet;
            if( !objectp(pet = new(__DIR__"pet.c")) ) {
                this_object()->force_me("say �ڪ����w�g���O�H�ȥ����F�A�U���Ц��I");
                return 1;
            }
            this_object()->force_me("say �A�������Ȫ����ڡA�o�������ڮ��h�Ȥ@�ȧa�I");
            this_object()->force_me("say ��A�u�ȧ��F�v�L�Ӹ�ڻ��I");
            switch( random(5) ) {
                case 0: pet->set("name", "�j����"); break;
                case 1: pet->set("name", "������"); break;
                case 2: pet->set("name", "�p��"); break;
                case 3: pet->set("name", "�p��"); break;
                case 4: pet->set("name", "�j�T��"); break;
            }
            pet->move(environment(me));
            pet->set_leader(me);
            me->add_quest(CATEGORY, ID, 1);
            me->set_temp("quest/" + CATEGORY+ID, pet);
            return 1;
        }
        
        if( me->query_quest(CATEGORY, ID) == 1 ) {
            this_object()->force_me("say �褣�O�s�A�ȤF�ܡH�٤��֥h���ڷȪ��C");
            this_object()->force_me("say ��A�u�ȧ��F�v�L�Ӹ�ڻ��I");
            return 1;
        }
        return 1;
    }

    if( arg == "�ȧ��F" ) {

        if( !me->query_quest(CATEGORY, ID) ) {
            this_object()->force_me("say �ڦ��ЧA�ӷȪ��ܡH");
        } else {
            object pet;
            if( !objectp(pet = me->query_temp("quest/" + CATEGORY + ID)) ) {
                this_object()->force_me("say ����I�H�A��ڪ����d��F�A�d���򰭡I�I");
                // �����Ȧs�����
                me->delete_quest(CATEGORY, ID);
                return 1;
            }

            if( pet->query("move_count") < 100 ) {
                this_object()->force_me("say ����I�H�A�Ȩ��G�B�T�B���s���Ȧn�F�H�֥h���ڷȡI");
                return 1;
            }

            this_object()->force_me("say ��A�Ȫ��ܦn�A�o�̤@�ʨ������h�a�I");
            this_object()->force_me("thank " + me->query_id());
            tell_object(me, "(�@�ʨ�Ȥl�w�g�۰ʦs�b�Ȧ�̡C)\n");
            me->add("bank", 100);

            // �[e�ť���1�I
            me->gain_score("elevel",1);
                    
            // �����Ȧs�����
            me->delete_temp("quest/" + CATEGORY + ID);
            me->delete_quest(CATEGORY, ID);
            destruct(pet);
        }
        return 1;
    }
    return 1;
} */
