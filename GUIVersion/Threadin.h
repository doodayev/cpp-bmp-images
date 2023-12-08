//---------------------------------------------------------------------------

#ifndef ThreadinH
#define ThreadinH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <filesystem>
#include <string>
#include <vector>
namespace fs = std::filesystem;
using namespace std;
//---------------------------------------------------------------------------
class TSortThread : public TThread
{
private:
    fs::path cp;
    vector<string> Files;
protected:
    void __fastcall Execute();
public:
    __fastcall TSortThread(const fs::path& cp, const vector<string>& Files, bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
