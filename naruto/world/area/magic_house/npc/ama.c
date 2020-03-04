#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�L���|", ({ "lin ama", "ama" }) );
    set_level(10);
    set_race("human");
    set("age", 21);
    set("no_fight", 1);
    set("title", "��������");
    set("long", "�@�y�ѹ�˪��C�~�A���G������������s�H�@�I�c�C\n");
    set("guard_exit", ({ "north" })); // �u�ۥX�f
    setup();
}
int do_guard_exit(int x, int y, string exit)
{
    if( this_player()->query("guild") == "hunter" && this_player()->query_temp("gomagic") != 1 ) {
        message_vision(CYN"$n�J�Ӫ��L�d�F$N�A�s���W���C�ڤ򳣤���L�C\n"NOR, this_player(), this_object());
        message_vision("$n���D�G"HIG"��ӬO"+this_player()->rank()+this_player()->query("name")+"���I�ڭ̹Ϊ����y�H�i�H�K�O�J���A�жi�I\n"NOR, this_player(), this_object());
        this_player()->set_temp("gomagic", 1);
    }
    if( this_player()->query_temp("gomagic") != 1) {
        message_vision(CYN"$n�J�Ӫ��L�d�F$N�A�s���W���C�ڤ򳣤���L�C\n"NOR, this_player(), this_object());
        message_vision("$n����@�Ծ�����Ӥj�����F�_�ӡC\n", this_player(), this_object());
        do_chat((: command, "say ��"+this_player()->query("name")+HIG"�O����¾�~�I�Q�u�i�h�v�N�o�I�O�I"NOR:));
        return 1;
    }
    return 0;
}
private void goin(string arg, object me)
{
    if( arg != "" ) {
        if( arg[0] == 'y' || arg[0] == 'Y' ) {
            if( this_player()->query("bank") < 5000 ) {
                tell_object(me, "\n�L���|���j�������D�G"HIG"�z�a�I�S���٨Ӥ������ΡI�^�a��ı�h�a�I\n"NOR);
                return;
            }
            tell_object(me, HIY"\n(�Ȧ�פF���d��Ȥl���]�N�����Ϊ��M�Τ��Y��)\n"NOR);
            tell_object(me, "�L���|�I�Y���D�G"HIG"���´f�U�I�o��j�ݽжi�I\n\n"NOR);
            this_player()->set_temp("gomagic", 1);
            this_player()->add("bank", -5000);
            return;
        } else if( arg[0] == 'N' || arg[0] == 'n' ) {
            tell_object(me, HIW"\n�A�߸̤@�Q�G�z�a�I���S���o��Q�I�u�O�L���|�I\n\n"NOR);
            return;
        }
    }
    tell_object(me, "�L���|���D�G"HIG"�J�������O���d��Ȥl�I"HIW"�n�h�ܡH(Y/n)"NOR);
    input_to("goin", me);
    return;
}
// ��char��say���O�ɡA��mob���^��
int relay_say(object me, string arg)
{
    if( arg == "�i�h" ) {
        if( !userp(me) ) return 0;
        if( me->query("guild") == "hunter" ) {
            tell_object(me, "�L���|���D�G"HIG"�o��"+me->rank()+"�i�H�����J����I\n"NOR);
        } else {
            tell_object(me, "�L���|���D�G"HIG"�J�������O���d��Ȥl�I"HIW"�n�h�ܡH(Y/n)"NOR);
            input_to("goin", me);
            return notify_fail("");
        }
    }
    return 1;
}
