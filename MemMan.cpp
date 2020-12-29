#include "MemMan.h"
#include "Windows.h"
#include <TlHelp32.h>

MemMan::MemMan()
{
	handle = NULL;
}

MemMan::~MemMan()
{
	CloseHandle(handle);
}

DWORD MemMan::getProcess(const char* proc)
{
	HANDLE hProcessId = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	DWORD process;
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(pEntry);

	do
	{
		if (!strcmp(pEntry.szExeFile, proc))
		{
			process = pEntry.th32ProcessID;
			CloseHandle(hProcessId);
			handle = OpenProcess(PROCESS_ALL_ACCESS, false, process);
		}

	} while (Process32Next(hProcessId, &pEntry));
	return process;
}

uintptr_t MemMan::getModule(DWORD procId, const char* modName)
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, procId);
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(mEntry);

	do
	{
		if (!strcmp(mEntry.szModule, modName))
		{
			CloseHandle(hModule);
			return (DWORD)mEntry.hModule;
		}
	} while (Module32Next(hModule, &mEntry));
	return 0;
}

DWORD MemMan::getAddress(DWORD addr, std::vector<DWORD> vect)
{
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		ReadProcessMemory(handle, (BYTE*)addr, &addr, sizeof(addr), 0);
		addr += vect[i];
	}
	return addr;
}


#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class oofdsqv {
public:
	double qyztqyxhc;
	string hhcqgunycg;
	oofdsqv();
	int kobpsttsqgdkvxpduohteffwb(bool hxxqqesycz, bool hyhruuye, double ooimftoxhyn, bool uqybpfqqycnvj);
	double ywydoldmvkvdmemmargcgaoz(bool zoxxndkppi);
	double ozjxetvhepagfugkobdvggak(double plcklaucf, int ptrldue);
	double fftjnvlxbeblymj(int daxcqeuu, int xbdkmfryzcaq);
	double fbthplxidt(bool tmgxgcbymzps, string hhjayzgzmmzzklb, int sxqajl, string omelylfx, string brsiotfthb, int cprcftxzeyslujt, string hqswlwbd, int fgbfhnkofjwlo);
	string dapfpgecpduxmmcmpawcro(int jmqmyw, bool zohffxjbtgl, double btafvg);
	string ujvrqzkorbshzy();

protected:
	bool czxknemnt;
	int pwfygiviotdzm;
	bool hkdewfo;
	string mwgutoigacrr;
	double jucwihlwmggdod;

	void fknuadchdlnlxfuxcfrwr(int auystqzrw);
	double gxlcsnegwiexihhm(bool tueduigqh, string lptogm, bool twhryuybnzw, double ztchvxqwat, double bszhdvdv, string owtqkusljmxge, bool kajqiwp, double syunwll);
	double oepeujjqgvj(int ozdkexziyl, double hdqzngvroyhxhcs, double pivhmpb, int gdpfsjzddgpncw);

private:
	double fkzssaccbaxchw;
	double amrgitmuarjsfb;
	int urdwcgfsitfgq;
	int mrfxh;
	string tbscqtaae;

	double hoxkvrysskfdayqufzdswria(int ntclxblhao, int uvufvmuzsgeyd, double rmsyqwkx, bool qsfgc);
	double ozvdgcwfmxizweqeq(bool pknthaaoldnfxk, string uhdgtcbbxqmqn, bool krdbgmrd);
	bool zexeakfhpesndsjlxrk(double tpramywyoewphk, string jiiunlshbppt);
	double iugkcmmfdbzqgkzcflaczhb(string rsrjvfsn, double hoitqfshfsydzki, string gzgkntiroejzkyx, double eyrspgu, bool ulddjr, double zofvolhdisvgxvb, string nrawnlfhet, int rqlujggiwvbnbe, double ndbvyrllxfyws);
	double anqxlgrisypcmeztfqtajee();

};



double oofdsqv::hoxkvrysskfdayqufzdswria(int ntclxblhao, int uvufvmuzsgeyd, double rmsyqwkx, bool qsfgc) {
	int irvtpdulnzared = 450;
	double vefsu = 12793;
	double clgyvbgt = 88363;
	double glqwpigbqiar = 85598;
	bool dywtxvx = false;
	string ijduibj = "thcywsmtxskafqxvxxagibpuudbeziiglveperusovqwlzrhurornqprxpmlhheisqocvmqhu";
	double rgpqoeakwsnpabo = 11302;
	string ysneumtzdprhq = "ifdrxjbokxkdbwpfeqydgjhfdjoaytcbrtbqvqejrdhrwyijmjjuzhidxdwthrz";
	double feouych = 27910;
	if (string("ifdrxjbokxkdbwpfeqydgjhfdjoaytcbrtbqvqejrdhrwyijmjjuzhidxdwthrz") == string("ifdrxjbokxkdbwpfeqydgjhfdjoaytcbrtbqvqejrdhrwyijmjjuzhidxdwthrz")) {
		int nrqp;
		for (nrqp = 62; nrqp > 0; nrqp--) {
			continue;
		}
	}
	if (450 != 450) {
		int kkzi;
		for (kkzi = 35; kkzi > 0; kkzi--) {
			continue;
		}
	}
	if (string("thcywsmtxskafqxvxxagibpuudbeziiglveperusovqwlzrhurornqprxpmlhheisqocvmqhu") == string("thcywsmtxskafqxvxxagibpuudbeziiglveperusovqwlzrhurornqprxpmlhheisqocvmqhu")) {
		int px;
		for (px = 46; px > 0; px--) {
			continue;
		}
	}
	if (85598 == 85598) {
		int oqaitfsmtm;
		for (oqaitfsmtm = 23; oqaitfsmtm > 0; oqaitfsmtm--) {
			continue;
		}
	}
	return 38024;
}

double oofdsqv::ozvdgcwfmxizweqeq(bool pknthaaoldnfxk, string uhdgtcbbxqmqn, bool krdbgmrd) {
	string dqjvi = "lpodqcxvkcpdsdjcykuqnhfxwmydbzoeabvvttyftpmdcbusvxzbntwdwvfxbibuoazfnya";
	if (string("lpodqcxvkcpdsdjcykuqnhfxwmydbzoeabvvttyftpmdcbusvxzbntwdwvfxbibuoazfnya") != string("lpodqcxvkcpdsdjcykuqnhfxwmydbzoeabvvttyftpmdcbusvxzbntwdwvfxbibuoazfnya")) {
		int mloez;
		for (mloez = 8; mloez > 0; mloez--) {
			continue;
		}
	}
	if (string("lpodqcxvkcpdsdjcykuqnhfxwmydbzoeabvvttyftpmdcbusvxzbntwdwvfxbibuoazfnya") == string("lpodqcxvkcpdsdjcykuqnhfxwmydbzoeabvvttyftpmdcbusvxzbntwdwvfxbibuoazfnya")) {
		int qv;
		for (qv = 75; qv > 0; qv--) {
			continue;
		}
	}
	return 13669;
}

bool oofdsqv::zexeakfhpesndsjlxrk(double tpramywyoewphk, string jiiunlshbppt) {
	double ltfdn = 17626;
	int mrvkf = 4017;
	string nijbbcvwanzkph = "jfordubulbdisejdeud";
	int gpaexngkhnta = 1208;
	if (string("jfordubulbdisejdeud") != string("jfordubulbdisejdeud")) {
		int kbyy;
		for (kbyy = 96; kbyy > 0; kbyy--) {
			continue;
		}
	}
	if (4017 != 4017) {
		int cojvxskyb;
		for (cojvxskyb = 78; cojvxskyb > 0; cojvxskyb--) {
			continue;
		}
	}
	if (1208 == 1208) {
		int qcvmeg;
		for (qcvmeg = 92; qcvmeg > 0; qcvmeg--) {
			continue;
		}
	}
	if (17626 != 17626) {
		int rffzex;
		for (rffzex = 75; rffzex > 0; rffzex--) {
			continue;
		}
	}
	if (1208 == 1208) {
		int hvijyvqi;
		for (hvijyvqi = 30; hvijyvqi > 0; hvijyvqi--) {
			continue;
		}
	}
	return false;
}

double oofdsqv::iugkcmmfdbzqgkzcflaczhb(string rsrjvfsn, double hoitqfshfsydzki, string gzgkntiroejzkyx, double eyrspgu, bool ulddjr, double zofvolhdisvgxvb, string nrawnlfhet, int rqlujggiwvbnbe, double ndbvyrllxfyws) {
	bool aoocrwlsg = false;
	string ejqzfcpvtu = "cjufjayqpxnaamznoobhxrhqxaqljbdrhcoefbrkyicmesacklpkrq";
	bool zjuaabfijg = false;
	string jedpcd = "mjxpzpzpahcbaptzxlcukgszxthyqfkeqgiuonswsnzlixtfujijueksnbwavafanpw";
	double djfpnrdepnrz = 26866;
	string gyddzhdggpnnca = "cgbxgdvqygyglnetketsjkiqmkyxlnhatvqusdpkjoov";
	int dvogfaq = 9514;
	string fqdbnsjjkcon = "bwhcfcmlhausbgrlshrjnprwqprhijlundocxpwawqowrnqmcufwyragqqnlrzpo";
	if (string("mjxpzpzpahcbaptzxlcukgszxthyqfkeqgiuonswsnzlixtfujijueksnbwavafanpw") == string("mjxpzpzpahcbaptzxlcukgszxthyqfkeqgiuonswsnzlixtfujijueksnbwavafanpw")) {
		int teukjuhiqi;
		for (teukjuhiqi = 14; teukjuhiqi > 0; teukjuhiqi--) {
			continue;
		}
	}
	return 18404;
}

double oofdsqv::anqxlgrisypcmeztfqtajee() {
	string ezcibi = "rgcdzonvvzkacenvtrrmezrkikuqroygodw";
	double qktibbj = 19162;
	bool llfxhppeiagok = true;
	bool hvccuenviz = true;
	double bjrwdtjz = 67200;
	double gvusmkyytckz = 31003;
	bool wauyfwagcgm = true;
	int hbmikchwtxgkrm = 563;
	if (19162 == 19162) {
		int haxv;
		for (haxv = 85; haxv > 0; haxv--) {
			continue;
		}
	}
	if (string("rgcdzonvvzkacenvtrrmezrkikuqroygodw") == string("rgcdzonvvzkacenvtrrmezrkikuqroygodw")) {
		int qfrfgx;
		for (qfrfgx = 81; qfrfgx > 0; qfrfgx--) {
			continue;
		}
	}
	if (19162 != 19162) {
		int lihn;
		for (lihn = 69; lihn > 0; lihn--) {
			continue;
		}
	}
	return 81295;
}

void oofdsqv::fknuadchdlnlxfuxcfrwr(int auystqzrw) {
	bool pumiupbjaawyxuu = true;
	string clfntzqs = "udvmakivycecsvqxzqwtkvzhvgflilxuklpjdjublrljjkdnbzur";
	double iljqhzpceyyv = 5573;
	bool xznwq = true;
	if (true == true) {
		int yqlkikiy;
		for (yqlkikiy = 6; yqlkikiy > 0; yqlkikiy--) {
			continue;
		}
	}
	if (true != true) {
		int bfccsfsg;
		for (bfccsfsg = 6; bfccsfsg > 0; bfccsfsg--) {
			continue;
		}
	}
	if (5573 != 5573) {
		int fbqxieklks;
		for (fbqxieklks = 66; fbqxieklks > 0; fbqxieklks--) {
			continue;
		}
	}
	if (true != true) {
		int mtxo;
		for (mtxo = 84; mtxo > 0; mtxo--) {
			continue;
		}
	}

}

double oofdsqv::gxlcsnegwiexihhm(bool tueduigqh, string lptogm, bool twhryuybnzw, double ztchvxqwat, double bszhdvdv, string owtqkusljmxge, bool kajqiwp, double syunwll) {
	double bnmlvvkroo = 25385;
	if (25385 != 25385) {
		int tmi;
		for (tmi = 70; tmi > 0; tmi--) {
			continue;
		}
	}
	if (25385 == 25385) {
		int kkfdn;
		for (kkfdn = 8; kkfdn > 0; kkfdn--) {
			continue;
		}
	}
	return 66429;
}

double oofdsqv::oepeujjqgvj(int ozdkexziyl, double hdqzngvroyhxhcs, double pivhmpb, int gdpfsjzddgpncw) {
	int anpvnzldijlq = 2795;
	bool hjrzmitvvlzlmq = false;
	bool dcozvnheppaq = false;
	string iagwtjgldxuwdh = "kr";
	bool cgoxxdhaegvmlve = true;
	int mzkfzdwnpptmk = 2832;
	string bbnxeascxig = "gpzcgygocolrsehfciiwkcedgzjgewtjzwvmxvufvvvwyga";
	string auorqtf = "mlnjvy";
	double tentakdbmqxbkjg = 1716;
	double vsggkgwmjaq = 36499;
	if (string("kr") == string("kr")) {
		int fwiz;
		for (fwiz = 20; fwiz > 0; fwiz--) {
			continue;
		}
	}
	if (string("kr") != string("kr")) {
		int bmwmgybw;
		for (bmwmgybw = 15; bmwmgybw > 0; bmwmgybw--) {
			continue;
		}
	}
	return 98258;
}

int oofdsqv::kobpsttsqgdkvxpduohteffwb(bool hxxqqesycz, bool hyhruuye, double ooimftoxhyn, bool uqybpfqqycnvj) {
	string qfbvlscbpyg = "fgusysckofeymfvewbggvfjroalmwnszbhoamirsesgaooikwibkrlgcaxalrglpytqjgqngmlqbzaxuiuwsx";
	bool reqxpywpuyd = true;
	if (string("fgusysckofeymfvewbggvfjroalmwnszbhoamirsesgaooikwibkrlgcaxalrglpytqjgqngmlqbzaxuiuwsx") != string("fgusysckofeymfvewbggvfjroalmwnszbhoamirsesgaooikwibkrlgcaxalrglpytqjgqngmlqbzaxuiuwsx")) {
		int udkujg;
		for (udkujg = 87; udkujg > 0; udkujg--) {
			continue;
		}
	}
	if (true != true) {
		int beqm;
		for (beqm = 41; beqm > 0; beqm--) {
			continue;
		}
	}
	return 79145;
}

double oofdsqv::ywydoldmvkvdmemmargcgaoz(bool zoxxndkppi) {
	int xrgpoqmq = 2204;
	bool hmbihng = true;
	string rgdmjvmlilfz = "h";
	int kddebpkysob = 2784;
	string sbwbqmci = "vc";
	bool ylmclntqks = true;
	double ckmbb = 68411;
	bool qgmofioyjsbezt = true;
	if (68411 == 68411) {
		int jjlzwxai;
		for (jjlzwxai = 94; jjlzwxai > 0; jjlzwxai--) {
			continue;
		}
	}
	return 45891;
}

double oofdsqv::ozjxetvhepagfugkobdvggak(double plcklaucf, int ptrldue) {
	int vrpqtiiv = 916;
	int ywkmsvvhvhxbx = 5066;
	bool yksxsfrye = true;
	double wjvxzyeighcp = 10947;
	double eqprwq = 60406;
	int zmuximyyo = 4569;
	double uzgpdpwxwylwx = 48104;
	string rbuofl = "blzvlofuraledcfjlatpjdjyuaftaivebtuctltsvasikuijeuwebylovsuimchxzdlqj";
	if (48104 == 48104) {
		int jgzh;
		for (jgzh = 54; jgzh > 0; jgzh--) {
			continue;
		}
	}
	if (string("blzvlofuraledcfjlatpjdjyuaftaivebtuctltsvasikuijeuwebylovsuimchxzdlqj") != string("blzvlofuraledcfjlatpjdjyuaftaivebtuctltsvasikuijeuwebylovsuimchxzdlqj")) {
		int qfjdg;
		for (qfjdg = 85; qfjdg > 0; qfjdg--) {
			continue;
		}
	}
	if (string("blzvlofuraledcfjlatpjdjyuaftaivebtuctltsvasikuijeuwebylovsuimchxzdlqj") == string("blzvlofuraledcfjlatpjdjyuaftaivebtuctltsvasikuijeuwebylovsuimchxzdlqj")) {
		int gosd;
		for (gosd = 100; gosd > 0; gosd--) {
			continue;
		}
	}
	if (10947 != 10947) {
		int wvfupitdfx;
		for (wvfupitdfx = 15; wvfupitdfx > 0; wvfupitdfx--) {
			continue;
		}
	}
	return 8909;
}

double oofdsqv::fftjnvlxbeblymj(int daxcqeuu, int xbdkmfryzcaq) {
	string cqxyyztroxx = "vaadjktktiaqqljbehtbfyvghnwmvslxmgwrmssjwdqwxsfiwfsexhvrtmsjybgbiicqwzregexpiitivzezkswkpjzxt";
	int cerde = 1490;
	int oxryxxiknfvug = 6138;
	int oqtlgs = 1862;
	int xkjkm = 1247;
	if (1862 == 1862) {
		int kw;
		for (kw = 77; kw > 0; kw--) {
			continue;
		}
	}
	if (1490 != 1490) {
		int ljabrffqs;
		for (ljabrffqs = 4; ljabrffqs > 0; ljabrffqs--) {
			continue;
		}
	}
	if (1490 != 1490) {
		int cqrkjtlfht;
		for (cqrkjtlfht = 50; cqrkjtlfht > 0; cqrkjtlfht--) {
			continue;
		}
	}
	if (string("vaadjktktiaqqljbehtbfyvghnwmvslxmgwrmssjwdqwxsfiwfsexhvrtmsjybgbiicqwzregexpiitivzezkswkpjzxt") != string("vaadjktktiaqqljbehtbfyvghnwmvslxmgwrmssjwdqwxsfiwfsexhvrtmsjybgbiicqwzregexpiitivzezkswkpjzxt")) {
		int dlfef;
		for (dlfef = 7; dlfef > 0; dlfef--) {
			continue;
		}
	}
	return 353;
}

double oofdsqv::fbthplxidt(bool tmgxgcbymzps, string hhjayzgzmmzzklb, int sxqajl, string omelylfx, string brsiotfthb, int cprcftxzeyslujt, string hqswlwbd, int fgbfhnkofjwlo) {
	double snwmtmkqh = 47740;
	if (47740 == 47740) {
		int ukoxuom;
		for (ukoxuom = 93; ukoxuom > 0; ukoxuom--) {
			continue;
		}
	}
	if (47740 != 47740) {
		int asccfu;
		for (asccfu = 2; asccfu > 0; asccfu--) {
			continue;
		}
	}
	if (47740 != 47740) {
		int omz;
		for (omz = 13; omz > 0; omz--) {
			continue;
		}
	}
	return 62235;
}

string oofdsqv::dapfpgecpduxmmcmpawcro(int jmqmyw, bool zohffxjbtgl, double btafvg) {
	int xmxkzctajj = 5747;
	if (5747 != 5747) {
		int ebabp;
		for (ebabp = 33; ebabp > 0; ebabp--) {
			continue;
		}
	}
	if (5747 != 5747) {
		int asps;
		for (asps = 13; asps > 0; asps--) {
			continue;
		}
	}
	if (5747 == 5747) {
		int euvnauxhk;
		for (euvnauxhk = 96; euvnauxhk > 0; euvnauxhk--) {
			continue;
		}
	}
	if (5747 == 5747) {
		int yb;
		for (yb = 68; yb > 0; yb--) {
			continue;
		}
	}
	return string("xunpuhixurwr");
}

string oofdsqv::ujvrqzkorbshzy() {
	int dnhivzfqeskas = 3511;
	int auxbnqpvd = 5278;
	int tzfxojhxy = 2578;
	if (3511 != 3511) {
		int ix;
		for (ix = 69; ix > 0; ix--) {
			continue;
		}
	}
	if (2578 == 2578) {
		int edfawx;
		for (edfawx = 15; edfawx > 0; edfawx--) {
			continue;
		}
	}
	if (5278 != 5278) {
		int rzc;
		for (rzc = 55; rzc > 0; rzc--) {
			continue;
		}
	}
	return string("");
}

oofdsqv::oofdsqv() {
	this->kobpsttsqgdkvxpduohteffwb(true, true, 24146, true);
	this->ywydoldmvkvdmemmargcgaoz(false);
	this->ozjxetvhepagfugkobdvggak(22540, 985);
	this->fftjnvlxbeblymj(3194, 1104);
	this->fbthplxidt(true, string("jggqemihhbkszzhxupzyxgeficdxd"), 1139, string("polijhjdetchzrustmpngrjptzjyfcwpyrkjbkqrvepoejglykstrpfdvdlkirgrgw"), string("gcorjynyliscszvpkdawxdowfxtvuiesj"), 5045, string("qhwwkgyovjedxpxrolr"), 2406);
	this->dapfpgecpduxmmcmpawcro(1474, true, 66788);
	this->ujvrqzkorbshzy();
	this->fknuadchdlnlxfuxcfrwr(4806);
	this->gxlcsnegwiexihhm(false, string("bololihcfbpckozojqsqeyufdaabzipyusif"), true, 19327, 43036, string("kwd"), false, 12535);
	this->oepeujjqgvj(4818, 75328, 36960, 1414);
	this->hoxkvrysskfdayqufzdswria(1680, 281, 10829, true);
	this->ozvdgcwfmxizweqeq(true, string("gvpzddihzsgilzeramypvlmdgfrlvbjhmxs"), false);
	this->zexeakfhpesndsjlxrk(18641, string("uytwiuhavuqvxmxxlplr"));
	this->iugkcmmfdbzqgkzcflaczhb(string("lqhgxfswt"), 49427, string("ah"), 3236, true, 34165, string("kjopcxvxvafhkhlflgxvapahuevplmhylbwvrokwkhtfvupoqqsxdxamtkrejzosbtzestnwkoaymnkoyfdat"), 3767, 58288);
	this->anqxlgrisypcmeztfqtajee();
}

