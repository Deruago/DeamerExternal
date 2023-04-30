#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_ENUMOBJECT_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_ENUMOBJECT_H

#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/AccessModifier.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"
#include <vector>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct EnumObject : public Type
	{
	private:
		std::vector<std::string> members;

	public:
		EnumObject(const std::string& type_ = "");
		~EnumObject() override = default;

	public:
		void AddMember(const std::string& member_);

	public:
		std::vector<std::string> GetMembers() const;
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_ENUMOBJECT_H
