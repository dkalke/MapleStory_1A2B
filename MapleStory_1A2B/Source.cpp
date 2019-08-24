#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <time.h>
using namespace std;
struct TUPLE
{
  int number[3];
};

enum LOCATION { F = 0, S = 1, T = 2 };
int main()
{
  while ( 1 )
  {
    system( "cls" );
    srand( time( NULL ) );

    vector<TUPLE> ans_pool;
    for ( int i = 1; i <= 9; i++ ) // �Ĥ@���
      for ( int j = 1; j <= 9; j++ ) // �ĤG���
      {
        // ���L�ۦP�Ʀr
        if ( j == i )
          j++;

        if ( j != 10 )
          for ( int k = 1; k <= 9; k++ ) // �ĤT���
          {
            // ���L�ۦP�Ʀr �ˬd�⦸
            if ( k == i || k == j )
              k++;
            if ( k == i || k == j )
              k++;

            if ( k != 10 )
            {
              TUPLE ans;
              ans.number[F] = i;
              ans.number[S] = j;
              ans.number[T] = k;
              ans_pool.push_back( ans );
            }
          }
      }

    int a_count = -1;
    int b_count = -1;
    while ( a_count != 3 )
    {
      int guess_index = rand() % ( int ) ans_pool.size();
      int guess_number[3] = { ans_pool[guess_index].number[F], ans_pool[guess_index].number[S], ans_pool[guess_index].number[T] };

      printf( "now choice is %d%d%d\n", guess_number[F], guess_number[S], guess_number[T] );

      printf( "How many A and B?" );
      scanf( "%d %d", &a_count, &b_count );

      
      // �p�⦳�X�ӬOB
      for ( int i = 0; i < ans_pool.size(); i++ )
      {
        int count = 0;
        if ( ans_pool[i].number[F] == guess_number[F] || ans_pool[i].number[F] == guess_number[S] || ans_pool[i].number[F] == guess_number[T] ) // �Ĥ@�ӼƦr�OB
          count++;
        if ( ans_pool[i].number[S] == guess_number[F] || ans_pool[i].number[S] == guess_number[S] || ans_pool[i].number[S] == guess_number[T] ) // �Ĥ@�ӼƦr�OB
          count++;
        if ( ans_pool[i].number[T] == guess_number[F] || ans_pool[i].number[T] == guess_number[S] || ans_pool[i].number[T] == guess_number[T] ) // �Ĥ@�ӼƦr�OB
          count++;

        
        if ( count == a_count + b_count )
        {
          if ( a_count == 0 && b_count == 0 )
          {
            ; // pass
          }
          else if ( a_count == 0 )
          {
            if ( ans_pool[i].number[F] != guess_number[F] && ans_pool[i].number[S] != guess_number[S] && ans_pool[i].number[T] != guess_number[T] )
            {
              ; // pass
            }
            else
            {
              ans_pool.erase( ans_pool.begin() + i );
              i--;
            }
          }
          else if ( a_count == 1 )
          {
            if ( ( ans_pool[i].number[F] == guess_number[F] ) ||
              ( ans_pool[i].number[S] == guess_number[S] ) ||
              ( ans_pool[i].number[T] == guess_number[T] ) ) // �Ĥ@�ӼƦr�OA �βĤG�ӼƦr�OA �βĤT�ӼƦr�OA
            {
              ; //pass
            }
            else
            {
              ans_pool.erase( ans_pool.begin() + i );
              i--;
            }
          }
        }
        else
        {
          ans_pool.erase( ans_pool.begin() + i );
          i--;
        }

        if ( i != -1 )
        {
          // �R���ۨ�
          if ( ans_pool[i].number[F] == guess_number[F] && ans_pool[i].number[S] == guess_number[S] && ans_pool[i].number[T] == guess_number[T] )
          {
            ans_pool.erase( ans_pool.begin() + i );
            i--;
          }
        }
      }
      
       //�C�X���צ�
      for ( int i = 0; i < ans_pool.size(); i++ )
      {
        printf( "%d%d%d\n", ans_pool[i].number[F], ans_pool[i].number[S], ans_pool[i].number[T] );
      }
      printf( "size of pool is %d\n", ans_pool.size() );
      
    }
  }
}