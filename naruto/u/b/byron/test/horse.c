#include <ansi.h>
#include <login.h>
inherit F_HORSE; // use inheritance by tmr 2006/12/08

void flee();

/*string *horse = ({
        HIY+" ���߰�"+NOR,
        HIR+" �����_��"+NOR,
        HIG+" �d����"+NOR,
        HIW+" �|����"+NOR,
        HIC+" �{�s���q"+NOR,
        CYN+" �R�E"+NOR,
        BLU+" �¯��@"+NOR,
        WHT+" �񳷯Q�"+NOR,
        HIW+" ���ɿ��"+NOR,
        MAG+" �a�ݰl��"+NOR,
        HIM+" �a���R��"+NOR,
        RED+" ���V�l��"+NOR,
});
*/

void create()
{
        set_name(MAG+"�a�ݰl��"+NOR,({"snow horse","horse"}));
        set("long","�o�O�Ѥ���U�a�ҷj���ӨӪ��W���A�A�p�G�n��L���W�r�Х�(name)�C\n");
        set("race","���~");
        set_weight(30000);

        set("limbs", ({ "�Y��","����","�e�}","��}","�Y��" }));
        set("verbs", ({ "bite","claw","crash" }));

        set("level", 5);
        set("age",10);

        set_temp("apply/damage",10);

        set("no_get",1);
        set("no_drop",1);
        set("amount",1);
        set("ridable",1);

        set("chat_chance",1);
        set("chat_msg",({
          (: command("dog") :),
          (: command("cat") :),
          this_object()->name()+"�b���W�]�F�]�C\n",
          (: command("pure") :),
          (: command("jump") :),
          (: command(":D") :),
          (: command(":)") :),
          (: command(":P") :),
        }));
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({ (: flee :) }));
        set("unit","��");
          set("value", 30000);
        set("member0","none");
        set("member1","none");
        set("member2","none");
        set("member3","none");
         set("max_remember", 5); // �O����
        set("speed", 2);

          set("speed", 2);
        setup();
        if( this_object()->query("buyer_id") ) 
        {
                set_living_name("com_horse/"+this_object()->query("buyer_id"));
                set("long", this_object()->query("long") + "�A�ݨ�o�ǰ��������W��F "+this_object()->query("buyer_id")+" �o�X���j�r�C\n");
        }
}



