#define DEBUG 0

#include <stdio.h>
#include <string>
#include <assert.h>
#include "IsoGraph.h"
#include "NautyGraph.h"
#include "AutoGraph.h"

using namespace std;

int main()
{
  bool d = false;
  int n;
  scanf("%d", &n);

  IsoGraph* g1 = new NautyGraph(d, n);
  IsoGraph* g2 = new AutoGraph(d, n);
  IsoGraph* g3 = new AutoGraph(d, n, true);

  int a, b, ord = 1;
  while (scanf("%d %d", &a, &b) != EOF)
  {
    a--, b--;

    if (DEBUG)
      g1->toggle(a, b);
    g2->toggle(a, b);
    g3->toggle(a, b);

    string s1 = "";
    if (DEBUG)
      s1 = g1->canonicalLabel().c_str();

    string s2 = g2->canonicalLabel().c_str();
    string s3 = g3->canonicalLabel().c_str();

    //printf("%s %s %s %d (%d, %d)\n", s1.c_str(), s2.c_str(), s3.c_str(), ord++, a, b);

    if (DEBUG)
      assert(s1 == s2);
    assert(s2 == s3);
  }

  printf("%lf, %d %d\n", 1.0 * g2->stat[0] / g2->stat[1], g2->stat[0], g2->stat[1]);
  printf("%lf, %d %d\n", 1.0 * g3->stat[0] / g3->stat[1], g3->stat[0], g3->stat[1]);

  return 0;
}
