#ifndef __DATA_STRUCT_H__
#define __DATA_STRUCT_H__

#include <string>
#include <vector>
#include <optional>

using namespace std;

namespace JsonStruct
{
	template<typename DataType /*= void*/>
	class DataMember
	{
	public:

		DataMember() = default;
		virtual ~DataMember() = default;

		inline void SetValue(DataType data)
		{
			m_Object = data;
		}

		inline bool HasValue()
		{
			return m_Object.has_value();
		}

		inline DataType GetValue()
		{
			return m_Object.value;
		}

	protected:

		DataMember(DataType initialData)
		{
			m_Object.emplace(initialData);
		}

	protected:

		string m_MemberName;
		optional<DataType> m_Object;
	};

	// Stores list of all members, Can set initial json members and also add other ones later.
	struct DataStruct
	{
		template<typename... Members>
		DataStruct(std::forward<Members...>())
		{

		}

		virtual ~DataStruct()
		{

		}

		vector<DataMember<void>> m_Members;
	};
}

#endif // !__DATA_STRUCT_H__
