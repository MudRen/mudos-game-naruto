mapping record = ([
    0: ([ "name": "",
          "long": "",
          "buff1": "move",
          "buff2": "carriage",
       ]),
    1: ([ "name": HIR"�H��",
          "long": "�Z�����b�Y�W�a���@������A�����O��γ~�C\n",
          "buff1": "attack",
          "buff2": "intimidate",
       ]),
    2: ([ "name": HIB"�H��",
          "long": "�Z�����b�Y�W�a���@���Ŧ�A�����O��γ~�C\n",
          "buff1": "armor",
          "buff2": "wittiness",
       ]),
    3: ([ "name": HIG"�H��",
          "long": "�Z�����b�Y�W�a���@�����A�����O��γ~�C\n",
          "buff1": "evadebuff",
          "buff2": "evade",
       ]),
    4: ([ "name": HIY"�H��",
          "long": "�Z�����b�Y�W�a���@������A�����O��γ~�C\n",
          "buff1": "exactbuff",
          "buff2": "exact",
       ]),
    5: ([ "name": HIR"����",
          "long": HIR"�Z�����b���R���F���V�������A�ݰ_�ӫD�`�}�G�C\n"NOR,
          "buff1": "attack",
          "buff2": "intimidate",
       ]),
    6: ([ "name": HIB"����",
          "long": HIB"�Z�����b���R���F�������i���A�ݰ_�ӫD�`�}�G�C\n"NOR,
          "buff1": "armor",
          "buff2": "wittiness",
       ]),
    7: ([ "name": HIG"���",
          "long": HIG"�Z�����b���R���F���l�������A�ݰ_�ӫD�`�}�G�C\n"NOR,
          "buff1": "evadebuff",
          "buff2": "evade",
       ]),
    8: ([ "name": HIY"����",
          "long": HIY"�Z�����b���R���F�������w���A�ݰ_�ӫD�`�}�G�C\n"NOR,
          "buff1": "exactbuff",
          "buff2": "exact",
       ]),
    9: ([ "name": RED"���",
          "long": RED"���Z�����p�A��몺�`���A���H�@�ز`���i�����Pı�C\n"NOR,
          "buff1": "attack",
          "buff2": "intimidate",
       ]),
   10: ([ "name": BLU"����",
          "long": BLU"���Z�����p�����몺�`�šA���H�@�ز`���i�����Pı�C\n"NOR,
          "buff1": "armor",
          "buff2": "wittiness",
       ]),
   11: ([ "name": GRN"����",
          "long": GRN"���Z�����p�O�L�몺�`��A���H�@�ز`���i�����Pı�C\n"NOR,
          "buff1": "evadebuff",
          "buff2": "evade",
       ]),
   12: ([ "name": YEL"�t��",
          "long": YEL"���Z�����p�d�h�몺�`���A���H�@�ز`���i�����Pı�C\n"NOR,
          "buff1": "exactbuff",
          "buff2": "exact",
       ]),
]);

void die()
{
    object wp;
    int i, a;

    // �]�w�Q�o�تF�誺 mob �����o�쪺���I���O 1 �I
    set_level(1);

    // �P�_�� mob ���`��үd�U���Z������
    switch( this_object()->query("wp_number") ) {
        case 1: wp = new(__DIR__"wp/broad_sword.c");
                break;
        case 2: wp = new(__DIR__"wp/thin_sword.c");
                break;
        case 3: wp = new(__DIR__"wp/stone_lance.c");
                break;
    }
    if( !objectp(wp) ) {
        destruct(wp);
        return;
    }
    // ��O�]�w����
    switch( random(1000) ) {
        case 0..25: wp->set("number", 40);
                       i = random(4)+9;
                       break;
        case 201..500: wp->set("number", 8);
                       i = random(4)+1;
                       break;
        case 701..800: wp->set("number", 20);
                       i = random(4)+5;
                       break;
        default: i = 0; wp->set("number", 4); break;
    }
    wp->set("name", record[i]["name"] + wp->query("name"));
    wp->set("long", wp->query("long") + record[i]["long"]);

    a = wp->query("number");
    switch( wp->query("wield_as") ) {
        case "righthand": wp->set("apply_weapon/righthand/"+record[i]["buff1"], a);
                          wp->set("apply_weapon/righthand/"+record[i]["buff2"], a*3/4);
                          break;
        case "lefthand": wp->set("apply_weapon/lefthand/"+record[i]["buff1"], a/2);
                         wp->set("apply_weapon/lefthand/"+record[i]["buff2"], a*3/8);
                         break;
        case "twohanded": wp->set("apply_weapon/twohanded/"+record[i]["buff1"], a/2);
                          wp->set("apply_weapon/twohanded/"+record[i]["buff2"], a*3/8);
                          break;
    }
    wp->delete("number");
    switch( random(100) ) {
        case 2: wp->set("name", RED"�U�N��"+wp->query("name")); wp->set("number", 1); break;
        case 14: wp->set("name", GRN"���ꪺ"+wp->query("name")); wp->set("number", 8); break;
        case 20: wp->set("name", BLU"���᪺"+wp->query("name")); wp->set("number", 3); break;
        case 32: wp->set("name", HIY"������"+wp->query("name")); wp->set("number", 6); break;
        case 44: wp->set("name", HIR"�`����"+wp->query("name")); wp->set("number", 2); break;
        case 57: wp->set("name", HIG"���R��"+wp->query("name")); wp->set("number", 4); break;
        case 75: wp->set("name", HIB"�N�z��"+wp->query("name")); wp->set("number", 7); break;
        case 89: wp->set("name", YEL"���t��"+wp->query("name")); wp->set("number", 5); break;
        default: wp->set("number", 0); break;
    }
    switch( wp->query("wield_as") ) {
        case "righthand": switch( wp->query("number") ) {
                              case 0: break;
                              case 1: wp->add("apply_weapon/righthand/str", 15); break;
                              case 2: wp->add("apply_weapon/righthand/str", 8); break;
                              case 3: wp->add("apply_weapon/righthand/con", 15); break;
                              case 4: wp->add("apply_weapon/righthand/con", 8); break;
                              case 5: wp->add("apply_weapon/righthand/dex", 15); break;
                              case 6: wp->add("apply_weapon/righthand/dex", 8); break;
                              case 7: wp->add("apply_weapon/righthand/int", 15); break;
                              case 8: wp->add("apply_weapon/righthand/int", 8); break;
                          break;
                          }
        case "lefthand": switch( wp->query("number") ) {
                              case 0: break;
                              case 1: wp->add("apply_weapon/lefthand/str", 7); break;
                              case 2: wp->add("apply_weapon/lefthand/str", 4); break;
                              case 3: wp->add("apply_weapon/lefthand/con", 7); break;
                              case 4: wp->add("apply_weapon/lefthand/con", 4); break;
                              case 5: wp->add("apply_weapon/lefthand/dex", 7); break;
                              case 6: wp->add("apply_weapon/lefthand/dex", 4); break;
                              case 7: wp->add("apply_weapon/lefthand/int", 7); break;
                              case 8: wp->add("apply_weapon/lefthand/int", 4); break;
                          break;
                          }
        case "twohanded": switch( wp->query("number") ) {
                              case 0: break;
                              case 1: wp->add("apply_weapon/twohanded/str", 12); break;
                              case 2: wp->add("apply_weapon/twohanded/str", 6); break;
                              case 3: wp->add("apply_weapon/twohanded/con", 12); break;
                              case 4: wp->add("apply_weapon/twohanded/con", 6); break;
                              case 5: wp->add("apply_weapon/twohanded/dex", 12); break;
                              case 6: wp->add("apply_weapon/twohanded/dex", 6); break;
                              case 7: wp->add("apply_weapon/twohanded/int", 12); break;
                              case 8: wp->add("apply_weapon/twohanded/int", 6); break;
                          break;
                          }
    }
    // �����~�Q�O�Э��n���ק��O
    wp->set("changed", 1);

    // ���~�̫�A��b�a�W
    if( environment(this_object())->is_area() ) move_side(wp, this_object());
    else wp->move(environment(this_object()));

    // ���`�ɲ��ͰT��
    message_vision("$N�{���e��W$n�������A���������b�a�W�C\n"NOR, this_object(), wp);
    ::die();
    return;
}
