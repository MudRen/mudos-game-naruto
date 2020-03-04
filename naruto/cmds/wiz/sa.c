/* sa.c
*/

#include <command.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create()  { seteuid(getuid()); }

void show_info(object me, mapping coord)
{
    int i;
mixed type;
mapping info, temp;
string msg;

info = environment(me)->query_info(coord["x_axis"], coord["y_axis"]);

if( !sizeof(info) ) return;

msg = sprintf(HIW"========================= %-8s (%2d,%2d) =========================\n"NOR,
          environment(me)->query("name"), coord["x_axis"], coord["y_axis"] );
    msg += BYEL"[�ɮ�]"NOR + " " + file_name(environment(me)) + ".c\n";

foreach(type in keys(info))
switch( type ) {
case "objects":// �s�b��y�ФW������
msg += BRED"[�t��]"NOR" �ثe�s�b��o�Ӯy�Ъ�����(objects)�G\n";
if( (i=sizeof(info["objects"])) ) {
while(i--)
msg += "       " + file_name(info["objects"][i]) + "\n";
}
break;

case "loaded":// �w�g���J������
msg += BRED"[�t��]"NOR" �w�g���J������(loaded)�G\n";
if( (i=sizeof(info["loaded"])) ) {
mixed *k, *v;
k = keys(info["loaded"]);
v = values(info["loaded"]);
while(i--)
msg += "       " + k[i] + "�G" + (objectp(v[i]) ? file_name(v[i]) : "���s�b") + "\n";
}
break;

case "loads":// �y�Эn���J������
msg += BBLU"[�]�w]"NOR" �y�и��J������(loads)�G\n";
    if( (i=sizeof(info["loads"])) ) {
    mixed *k, *v;
    k = keys(info["loads"]);
    v = values(info["loads"]);
    while(i--)
    msg += "       �ɮסG" + k[i] + ", �ƶq�G" + v[i] + "\n";
    }
break;

case "room_exit":// �y�Ъ��ж������X�f
msg += BBLU"[�]�w]"NOR" �ж������X�f(room_exit) �ɮסG" + info["room_exit"] + "\n";
break;

case "area_exit":// �y�Ъ��ϰ쫬���X�f
msg += BBLU"[�]�w]"NOR" �ϰ쫬���X�f(area_exit) �ɮסG" + info["area_exit"]["filename"];
    msg += "  ���СG(" + info["area_exit"]["x_axis"] + "," + info["area_exit"]["y_axis"] + ")\n";
break;

case "detail":
msg += BBLU"[�]�w]"NOR" �Ӹ`�y�z(detail)�G\n";
    if( (i=sizeof(info["detail"])) ) {
    mixed *k, *v;
    k = keys(info["detail"]);
    v = values(info["detail"]);
    while(i--)
    msg += "       " + k[i] + "�G" + v[i] + "\n";
    }
break;
case "guard":
break;
default:// �䥦�]�w
msg += BGRN"[�]�w]"NOR" ";
    msg += type + "�G" + info[type] + "\n";
break;
}
msg += HIW"====================================================================\n"NOR;
write(msg);
}

int main(object me, string arg)
{
    mixed value;
    string type, control, file;
    mapping info;
    
    SECURED_WIZARD_COMMAND;

if( !environment(me) ) return 0;

if( !environment(me)->is_area() ) {
write("�o���O�u��b�ϰ줤�ϥΡC\n");
return 1;
}
    file = base_name(environment(me));

    if( file[0..6] == "/world/" && wiz_level(me) < 4 ) {
        write("�A�S���v�Q�s��o�Ӧa�ϡC\n");
        return 1;
    }

    if( !(info = me->query("area_info") ) ) {
    write("�ϥΫ��O�X�{���~�C\n");
    return 1;
    }

if( !arg ) {
show_info(me, info);
return 1;
}

    if( arg == "save" ) {
    if( environment(me)->save() ) {
    write("�ϰ��x�s���\\�C\n");
    return 1;
    }
    write("�ϰ��x�s���ѡC\n");
    return 1;
    }

    if( arg == "save_ansi") {
    environment(me)->map_ansi_save();
    return 1;
    }
    
    if( arg == "save_html") {
    environment(me)->map_html_save();
    return 1;
    }
    
    if( arg == "loads") {
  int x, y, i;
   string *lolo;
   lolo = environment(me)->query_LOLO();
   if( (i=sizeof(lolo)) > 0 ) {
   write("==================== �ثe�o�Ӱϰ즳���J���󪺮y�� ====================\n");
   while(i--) {
   if( sscanf(lolo[i], "%d,%d", y, x) == 2 ) {
   write(sprintf("(%2d,%2d) ", x, y));
   if( i >= 8 && i%8 == 0 ) write("\n");
   } 
   }
   write("\n======================================================================\n");
   } else write("�o�Ӱϰ�ثe���٨S���n���J������C\n");
   return 1;
    }

    if( arg == "pattern" ) {
        AREA_PATTERN_D->listPatterns();
        return 1;
    }

    if( sscanf(arg, "%s %d -%s", type, value, control) == 3 ) {
        if( type == "pattern" && control == "s" ) {
            AREA_PATTERN_D->setPattern(me, value);
            write("ok.\n");
            return 1;
        }
    }

    if( sscanf(arg, "%s %d", type, value) == 2 ) {
        if( type == "pattern" ) {
            AREA_PATTERN_D->patternInfo(value);
            return 1;
        }
    }

if( sscanf(arg, "%s %d", type, value) != 2 )
if( sscanf(arg, "%s %s", type, value) != 2) {
write("���O�ѼƤ����T�C\n");
return 1;
}

    if( value == "delete") {
    if( type == "loads" ) {
    if( !environment(me)->del_loads(info["x_axis"], info["y_axis"], value) ) {
    write("�R���y�и��J���󥢱ѡC\n");
    return 1;
    }
    write("�R���y�и��J���󦨥\\�C\n");
    return 1;
    }
    if( !environment(me)->delete_data(info["x_axis"], info["y_axis"], type) ) {
    write("�R�����ѡC\n");
    return 1;
    }
write("�A�N�y�� (" + info["x_axis"] + "," + info["y_axis"] + ") �� " + type + " ��ƧR���C\n");
    return 1;
    }

    // �]�w�ϰ�Φ��X�f
    if( type == "area_exit" ) {
int x, y;
string filename;
if( sscanf(value, "%s %d %d", filename, x, y) != 3 ) {
write("�ϰ�Φ��X�f�]�w���~�C (���O�榡�Gsa area_exit FILE_NAME X_AXIS Y_AXIS)\n");
return 1;
}
if( !environment(me)->set_area_exit(info["x_axis"], info["y_axis"], filename, x, y) ) {
write("�ϰ�Φ��X�f�]�w���ѡC\n");
return 1;
} 
write("�ϰ�Φ��X�f�]�w���\\�C\n");
    return 1;
    }

    // �]�w���J����
    if( type == "loads" ) {
    int amount;
    string filename;
    if( sscanf(value, "%s %d", filename, amount) != 2 ) {
    write("�ϰ���J����]�w���~�C (���O�榡�Gsa loads FILE_NAME AMOUNT)\n");
    return 1;
    }
    
    if( !environment(me)->set_loads(info["x_axis"], info["y_axis"], filename, amount) ) {
    write("�ϰ���J����]�w���ѡC\n");
    return 1;
    }
    write("�ϰ���J����]�w���\\�C\n");
    return 1;
    }

    if( type == "detail" ) {
    string title, detail;
    if( sscanf(value, "%s %s", title, detail) == 2 ) {
    if( environment(me)->set_area_detail(info["x_axis"], info["y_axis"], title, detail) )
    write("�]�w�Ӹ`�y�z���\\�C\n");
    } else write("�]�w�Ӹ`�y�z���ѡC\n");
    return 1;
    }

    // �p�G�O�]�wicon���ഫ��X
if( type == "icon" ) {
value = color(value);
if( sizeof(uncolor(value)) != 2 ) {
write("�]�w�y�ФW��icon���ݬO�G�Ӧr���j�p�C\n");
return 1;
}
}

    // �䥦���س]�w
   if( !environment(me)->set_data(info["x_axis"], info["y_axis"], type, value) ) {
write("�]�w���ѡC\n");
return 1;
}

write("�A�N�y�� (" + info["x_axis"] + "," + info["y_axis"] + ") �� " + type + " ��Ƴ]�w�� " + value + " �C\n");

return 1;
}

int help(object me)
{
    string msg = "�o�O���O�O�Ψӳ]�w�ϰ�y�Ь�����ƪ����O(�ثe�ҳB���y��)�C\n"
BBLU"\n1. ���O�榡�G sa\n"NOR
"   �i�H�C�X�ثe�ҳB�y�Ъ�������T�C\n"
BBLU"\n2. ���O�榡�G sa loads\n"NOR
"   �d�߰ϰ줤�|���J���󪺩Ҧ��y�ЦC��C\n"
BBLU"\n3. ���O�榡�G sa loads FILE_NAME AMOUNT\n"NOR
"   �o�ӫ��O�i�H�]�w�ثe���B���y�СA�|�۰ʸ��J�Y����󦹮y�Ф��C\n"
"   �ҡG sa loads __DIR__npc 2      �o�˷|���J�۹�ؿ����|�����ɦWnpc�G���b�y�ФW�C\n"
"        sa loads __DIR__npc/mob 4  �o�˷|���J�۹���|��npc�ؿ��U��mob�ɮץ|���b�y�ФW�C\n"
BBLU"\n4. ���O�榡�G sa area_exit FILE_NAME X_AXIS Y_AXIS\n"NOR
"   �o�ӫ��O�i�]�w�ϰ쫬�����X�f�C\n"
"   �ҡG sa area_exit __DIR__area 50 20  ��H������o�̮ɡA�|�۰��ಾ��area�o�Ӱϰ쪺(50,20)��m�C\n"
BBLU"\n5. ���O�榡�G sa room_exit FILE_NAME\n"NOR
"   �o�ӫ��O�i�H�]�w�ж��������X�f�C\n"
"   �ҡG sa room_exit __DIR__room  ��H������o�̮ɡA�|�۰��ಾ��ж�room���C\n"
BBLU"\n6. ���O�榡�G sa detail TITLE DETAIL\n"NOR
"   �o�ӫ��O�O�Ψӳ]�w�ж����Ӹ`�y�z���A�䴩search, look���O�A���Ω�quest�C\n"
"   �ҡG sa detail �j�� �o�O�@�ʤj��A�γ\\�A�i�H��(climb)�W�h�C\n"
BBLU"\n7. ���O�榡�G sa TYPE VALUE\n"NOR
"   �o�ӫ��O�O�Ψӳ]�w�䥦�\\�઺�]�w�C\n"
"   �ҡG sa icon $YEL$��$NOR$  �]�w�ϥ�, �����O�䴩��X�C\n"
"        sa no_fight 1         �D�԰�\n"
"        sa nonprompt_icon 1   ���|�Y�ɧ��ܹϥܪ��]�w(�N��O�H���B���󲾨�o�y�Юɹϥܤ��|����)\n"
"        sa short �D��         �]�w�y�Ъ��u�ǭz\n"
"        sa long xxxxxxxx      �]�w�y�Ъ����ǭz�A�p�G�Ӫ��̦n�t�Xto���O, �p�G to sa long\n"
"        sa block 1            �]�w������ê�ϡA�L�k���ʹL�ӡC\n"
BBLU"\n8. ���O�榡�G sa TYPE delete\n"NOR
"   �o�O�ΨӧR���ϰ��ƪ����O�C\n"
"   �ҡG sa loads delete      �R���y�Ъ����J����\n"
"        sa area_exit delete  �R���y�Ъ��ϰ쫬���X�f\n"
"        sa room_exit delete  �R���y�Ъ��ж������X�f\n"
"        sa icon delete       �R���y�Ъ��ϥ�\n"
BBLU"\n9. ���O�榡�G sa save\n"NOR
"   �o�O�x�s�ϰ��ɮת����O�A��ϰ찵�F�@���ܧ��A���ݨϥΦ����O���x�s�C\n"
BBLU"\n10. ���O�榡�G sa save_ansi\n"NOR
"   �o�O�x�s�ϰ���Ϫ����O�A�ΨӰt�Xmap���O�C\n"
BBLU"\n11. ���O�榡�G sa save_html\n"NOR
"   �o�O�x�s�ϰ���Ϫ����O�A�Ω�����W�C\n"
"\n���G�b�ϰ�̥i�ϥΪ��ɮ׸��|�G\n"
"      __DIR__     �۹���|�A�ϰ쪺�ؿ��b�� __DIR__ �K���V��\n"
"      _DIR_AREA_  ���V /world/area/ �ؿ��U\n"
"      _DIR_NPC_   ���V /world/npc/ �ؿ��U\n"
"      _DIR_WP_    ���V /world/wp/ �ؿ��U\n"
"      _DIR_EQ_    ���V /world/eq/ �ؿ��U\n"
"      _DIR_ITEM_  ���V /world/item/ �ؿ��U\n"
"      _DIR_WORLD_ ���V /world/ �ؿ��U\n"
BRED"\n12. ���O�榡�Gsa pattern           "NOR"  �C�X�i�Ϊ� Area Pattern\n"
BRED"              sa pattern <�s��>    "NOR"  ��ܬY�s���� Area Pattern ���e\n"
BRED"              sa pattern <�s��> -s "NOR"  �N�Y�s���� Area Pattern �M�Φb���B��area��\n";
    me->start_more(msg);
    return 1;
}
