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
	shared_ptr<FruitStruct> pFruits = std::make_shared<FruitStruct>();
	pFruits->Initialize(&testFruitJson);

	pFruits->Add("isRipe", true);
	bool bIsRipe = *pFruits->Get<bool>("isRipe");
	bool bIsEaten = pFruits->Get("isEaten", false);

	pFruits->Add("isEaten", true);
	bIsEaten = pFruits->Get("isEaten", false);

	pFruits->Add<string>("fruit", "pineapple");
	string fruit(*pFruits->Get<string>("fruit"));

	int d = 0;
}