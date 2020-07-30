#include "PCH.h"

// TEST
using namespace JsonStruct;

const char* testFruitJson = R"V0G0N(
{
	"fruit": "Apple",
	"isRipe": "false"
}
)V0G0N";


class FruitStruct : public DataStruct
{
public:
	FruitStruct() : DataStruct
	{
		DataMember<string>("fruit"),
		DataMember<bool>("isRipe")
	}
	{}
};
// END TEST

int main()
{
	FruitStruct* pFruits = new FruitStruct();

	delete pFruits;
	pFruits = nullptr;
}