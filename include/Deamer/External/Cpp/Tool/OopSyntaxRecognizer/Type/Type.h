#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_TYPE_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_TYPE_H

#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/TypeCategory.h"
#include <string>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct Type
	{
		TypeCategory category;
		std::string type;

		Type(TypeCategory category_, const std::string& type_);

		virtual ~Type() = default;

		void SetTypeName(const std::string& type_);

		std::string GetTypeName() const;
		TypeCategory GetCategory() const;

		virtual void Print();
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_TYPE_H
