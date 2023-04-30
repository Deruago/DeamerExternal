#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_BASETYPEOBJECT_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_BASETYPEOBJECT_H

#include "Deamer/External/Cpp/Tool/OopToPlantUML/Template/ClassDiagram/ClassDiagramTemplate.h"
#include <vector>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct Type;

	struct BaseTypeObject
	{
		Type* type;

	public:
		BaseTypeObject() = default;
		~BaseTypeObject() = default;

	public:
		void SetType(Type* type_);

	public:
		Type* GetType() const;
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_BASETYPEOBJECT_H
