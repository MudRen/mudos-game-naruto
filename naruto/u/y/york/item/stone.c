#include <login.h> 
inherit ITEM;

void create()
{
    set_name("�����", ({ "jump stone","stone"}));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�@���p���Y�A�W���x�ۯ��������~\n�n���u���Ův�̤~���D�γ~�C");
    }
    setup();
}

void init()
{
    add_action("do_move", "move");
}

int do_move(string arg)
{

   switch(arg) {
      case "wizard": this_player()->move("/world/area/wizard/guildhall.c");break;
      case "muye": this_player()->move("/world/area/muye/inn.c");break;
      case "wild": this_player()->move("/world/area/wild/house.c");break;
      default: break;
   }

   return 1;
}
