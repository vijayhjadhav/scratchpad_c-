#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
    #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
    // Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
    // allocations to be of _CLIENT_BLOCK type
#else
    #define DBG_NEW new
#endif

struct Pod {
    int x;
};

void main() {
    Pod* pPod1 = DBG_NEW Pod;
    Pod *pPod = DBG_NEW Pod; // Oops, leaked the original pPod!
    //delete pPod1;
	delete pPod;
    _CrtDumpMemoryLeaks();
}