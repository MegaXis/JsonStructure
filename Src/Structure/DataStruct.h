#ifndef __DATA_STRUCT_H__
#define __DATA_STRUCT_H__

#include <string>
#include <vector>
#include <map>
#include <optional>
#include <any>

using namespace std;

namespace JsonStruct
{
	// Class used to contain the actual data of the taret member. Type is dependent on what you set for the member
	// If the value types mismatch, the value will result in a null / defualt value.
	template<typename DataType /*= void*/>
	class DataMember
	{
	public:

		DataMember()
		{
		}

		DataMember(string memberName)
		{
			m_MemberName = memberName;
		}

		DataMember(string memberName, DataType memberValue)
		{
			m_MemberName = memberName;
			m_Object = memberValue;
		}

		template<typename OtherType>
		DataMember(DataMember<OtherType> &member)
		{
			m_MemberName = member.GetName();

			if (member.HasValue())
			{
				m_Object = member.GetObject();
			}
		}

		virtual ~DataMember() = default;

		inline virtual void Initialize(void* pJson/* INSERT JSON LIBRARY FORMAT OF CHOICE TODO: Later make it work without having to be explicit*/)
		{

		}

		inline void SetValue(DataType data)
		{
			m_Object = data;
		}

		inline bool HasValue()
		{
			return m_Object.has_value();
		}

		inline DataType &GetValue()
		{
			return m_Object.value();
		}

		template<typename Type>
		inline Type* GetValuePtr()
		{
			return &m_Object.value();
		}

		inline string GetName()
		{
			return m_MemberName;
		}

		inline optional<DataType> &GetObject()
		{
			return m_Object;
		}

	protected:

		string m_MemberName;
		optional<DataType> m_Object;
	};

	// Stores list of all members, Can set initial json members and also add other ones later.
	// Can be used to access members and ask for values if they exist.
	class DataStruct
	{
	public:
		template<typename ...Members>
		DataStruct(Members&& ...rMembers)
		{
			//TODO: Find more efficient way to do all this.
			initializer_list<DataMember<any>> memberList{ std::forward<Members>(rMembers)...};
			for (DataMember<any> rMember : memberList)
			{
				m_Members.insert({ rMember.GetName(), std::move(rMember) });
			}
		}

		virtual ~DataStruct() = default;

		virtual void Initialize(void* pJson/* INSERT JSON LIBRARY FORMAT OF CHOICE TODO: Later make it work without having to be explicit*/);
		void Test_Init();

		template<typename Type>
		DataMember<Type> GetMemberNonNull(string memberName);
		DataMember<any> GetMemberNonNull(string memberName);

		template<typename Type>
		Type* Get(string memberName);

		template<typename Type>
		Type Get(string memberName, Type default);

		template<typename Type>
		void Add(string memberName, Type member);

	protected:
		map<string, DataMember<any>> m_Members;
	};

	#include "DataStruct_inl.h"
	// INL(DataStruct)
}

#endif // !__DATA_STRUCT_H__
