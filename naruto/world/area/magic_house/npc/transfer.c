#include <ansi.h>
#include <npc.h>

void create()
{
    set_name("�ǰe�v", ({ "transfer" }) );
    set_race("human");
    set_level(20);
    set("nickname",BMAG+HIW"���w�ǰe"NOR);
    set("gender", "female");
    set("no_fight", 1);
    set("age", 15);
    set("long", "�]�N�����Ϊ��M�ݶǰe�v�A�q�`�O�b�C�ȿ˦ۤW�O���M�I��t�ɨƥ�\n"
                "�N�C�ȶǨ�w�����a��A�Ǧ^���A���L��ƤH�P�[���S�H���D�N�O\n"
                "���`�b�����θ̨S����u�@�A�ҥH�����]�|���~�H�A�ȡC\n"
                "�p�G���N�@�ǰe��\�H�����A�i�H�V�L�M��(say �ǰe)\n");

    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say �Q�n�ǰe��\�ڳ����ܡH�ݧڡu�ǰe�v�N��F..." :),
    }));
    setup();
}
private void goin(string arg, object me)
{
    if( arg != "" ) {
        if( arg[0] == 'y' || arg[0] == 'Y' ) {
            if( this_player()->query("bank") < 500 ) {
                tell_object(me, HIM"\n�ǰe�v�L�`���n�n����ۥk�䪺�P�l�A�W���g�ۡu���}�U��v\n"NOR);
                return;
            }
            this_player()->delete_temp("gomagic");
            tell_object(me, HIY"\n(�Ȧ�פF���ʨ�Ȥl��ǰe�v�����Y��)\n"NOR);
            tell_object(me, HIM"�ǰe�v�I�I�Y�Ψ��Ĳ�I�A�A�A�u���v�a�@�n����F�\�ڳ������¤W�C\n\n"NOR);
            this_player()->move("/world/area/thorn_pine/altar02.c");
            this_player()->add("bank", -500);
            return;
        } else if( arg[0] == 'N' || arg[0] == 'n' ) {
            tell_object(me, HIW"\n�A�Q�F�Q�٬Oı�o�ӶQ�F�A�M�w�ۤv���L�h�C\n"NOR);
            return;
        }
    }
    tell_object(me, "�ǰe�v���D�G"HIG"�h�\�ڳ����ǰe�@���n���ʨ�Ȥl..."HIW"�n�h�ܡH(Y/n)"NOR);
    input_to("goin", me);
    return;
}
// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    object test;

    if( arg == "�ǰe" ) {
        if( !userp(me) ) return 0;
        tell_object(me, "�ǰe�v���D�G"HIG"�h�\�ڳ����ǰe�@���n���ʨ�Ȥl..."HIW"�n�h�ܡH(Y/n)"NOR);
        input_to("goin", me);
        return notify_fail("");
    }
    return 1;
}
