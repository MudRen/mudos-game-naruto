/* �}���n��
   (4) �R��      35001 ~ 75000
   (3) �R�q      15001 ~ 35000
   (2) �L�q       6001 ~ 15000
   (1) �ͦn        101 ~ 6000
   (0) ����       -100 ~ 100
  (-1) �N�H       -101 ~ -6000
  (-2) �ĵ�      -6001 ~ -15000
  (-3) �Ĺ�     -15000 ~ -35000
  (-4) ����     -35000 ~ -75000
*/

#define CAMP_DIR "/world/camp/"
#define MAX 75000
#define MIN -75000
#include <ansi.h>
#include <dbase.h>

mapping camp = ([]);

mapping getCamps() { return camp; }

string getCampRank(string c)
{
    int value;
    string camp_dir;

    if( undefinedp(camp[c]) ) return "����";

    if( !CAMP_D->getCampFile(c) ) return "����";
    
    value = camp[c];
    
    if( value >= -100 && value <= 100 ) return "����";
    if( value >= 101 && value <= 6000 ) return "�ͦn";
    if( value >= 6001 && value <= 15000 ) return "�L�q";
    if( value >= 15001 && value <= 35000 ) return "�R�q";
    if( value >= 35001 ) return "�R�q";
    
    if( value <= -101 && value >= -6000 ) return "�N�H";
    if( value <= -6001 && value >= -15000 ) return "�ĵ�";
    if( value <= -15001 && value >= -35000 ) return "�Ĺ�";
    if( value <= -35001) return "����";
    
    return "����";
}

int getCampScore(string c)
{
    int value;
    string camp_dir;

    if( undefinedp(camp[c]) ) return 0;

    if( !CAMP_D->getCampFile(c) ) return 0;
    
    value = camp[c];
    
    if( value >= -100 && value <= 100 ) return 0;
    if( value >= 101 && value <= 6000 ) return 1;
    if( value >= 6001 && value <= 15000 ) return 2;
    if( value >= 15001 && value <= 35000 ) return 3;
    if( value >= 35001 ) return 4;
    
    if( value <= -101 && value >= -6000 ) return -1;
    if( value <= -6001 && value >= -15000 ) return -2;
    if( value <= -15001 && value >= -35000 ) return -3;
    if( value <= -35001) return -4;
    
    return 0;
}

// �s�W�@�Ӱ}��
int addCamp(string c)
{
    string camp_dir;
    
    if( !undefinedp(camp[c]) ) return 0;
    if( !CAMP_D->getCampFile(c) ) return 0;

    tell_object(this_object(), HIY"�A�b�}��u" + CAMP_D->getCampName(c) + "�v�����n��A�F�줤�ߡC\n"NOR);

    camp[c] = 0;
    return 1;
}

// �R���@�Ӱ}��
int removeCamp(string c)
{
    string camp_dir;

    if( undefinedp(camp[c]) ) return 0;
    if( !CAMP_D->getCampFile(c) ) return 0;

    tell_object(this_object(), HIY"�A�b�}��u" + CAMP_D->getCampName(c) + "�v�����n��w�g�����C\n"NOR);
    map_delete(camp, c);
    return 1;
}

private void changeCamp(string c, int cnt)
{
    if( undefinedp(camp[c]) ) return;
    camp[c] += cnt;
    if( camp[c] > MAX ) camp[c] = MAX;
    else if( camp[c] < MIN ) camp[c] = MIN;
}

// ���@�Ӱ}����ܨ��n��
int updateCamp(string c, int cnt)
{
    int sign, value;
    string camp_dir, cam, *camps;

    if( !CAMP_D->getCampFile(c) ) return 0;
    if( undefinedp(camp[c]) ) addCamp(c);

    if( cnt >= 0 ) {
        sign = 1;
        value = cnt;
    } else {
        sign = -1;
        value = -cnt;
    }

    if( sign == 1 )
        tell_object(this_object(), HIY"�A�b�}��u" + CAMP_D->getCampName(c) + "�v�����n�洣�ɤF " + value + " �I�C\n"NOR);
    else
        tell_object(this_object(), HIB"�A�b�}��u" + CAMP_D->getCampName(c) + "�v�����n�歰�C�F " + value + " �I�C\n"NOR);
    
    changeCamp(c, sign*value);

    // �ͦn�P�Ĺ諸�}��]�|����ܰ�
    
    // �ͦn
    camps = CAMP_D->getFriendly(c);
    foreach( cam in camps ) {
        int v = random(value)+1;
        
        if( !CAMP_D->getCampFile(cam) ) return 0;
        
        if( sign == 1 )
            tell_object(this_object(), HIY"�A�b�}��u" + CAMP_D->getCampName(cam) + "�v�����n�洣�ɤF " + v + " �I�C\n"NOR);
        else
            tell_object(this_object(), HIB"�A�b�}��u" + CAMP_D->getCampName(cam) + "�v�����n�歰�C�F " + v + " �I�C\n"NOR);
        
        if( undefinedp(camp[cam]) ) camp[cam] = 0;
        changeCamp(cam, sign*v);
    }

    // �Ĺ�
    sign = -sign;
    camps = CAMP_D->getAdversely(c);
    foreach( cam in camps ) {
        int v = random(value)+1;

        if( !CAMP_D->getCampFile(cam) ) return 0;
        
        if( sign == 1 )
            tell_object(this_object(), HIY"�A�b�}��u" + CAMP_D->getCampName(cam) + "�v�����n�洣�ɤF " + v + " �I�C\n"NOR);
        else
            tell_object(this_object(), HIB"�A�b�}��u" + CAMP_D->getCampName(cam) + "�v�����n�歰�C�F " + v + " �I�C\n"NOR);
        
        if( undefinedp(camp[cam]) ) camp[cam] = 0;
        changeCamp(cam, sign*v);
    }

    return 1;
}

// �����]�w�Y�}�窺�n���
int setCamp(string c, int cnt)
{
    string camp_dir;

    if( !CAMP_D->getCampFile(c) ) return 0;
    if( undefinedp(camp[c]) ) addCamp(c);

    if( cnt >=0  )
        tell_object(this_object(), HIY"�A�b�}��u" + CAMP_D->getCampName(c) + "�v�����n�洣�ɤF " + cnt + " �I�C\n"NOR);
    else
        tell_object(this_object(), HIB"�A�b�}��u" + CAMP_D->getCampName(c) + "�v�����n�歰�C�F " + cnt + " �I�C\n"NOR);
    
    changeCamp(c, cnt);

    return 1;
}


// ���o�Y�}�窺��
int getCamp(string c)
{
    if( undefinedp(camp[c]) ) return 0;
    return camp[c];
}

// �O�_�s�b�Ӱ}�窺�n��
int hasCamp(string c)
{
    if( undefinedp(camp[c]) ) return 0;
    return 1;
}
