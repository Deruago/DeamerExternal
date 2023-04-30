#ifndef DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_STRUCTOBJECT_H
#define DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_STRUCTOBJECT_H

#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/AccessModifier.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/Type.h"
#include <vector>

namespace deamer::external::cpp::tool::oopsyntaxrecognizer
{
	struct PropertyObject;
	struct FunctionObject;
	struct BaseTypeObject;

	struct StructObject : public Type
	{
		std::vector<FunctionObject*> publicFunctionObjects;
		std::vector<FunctionObject*> protectedFunctionObjects;
		std::vector<FunctionObject*> privateFunctionObjects;

		std::vector<PropertyObject*> publicPropertyObjects;
		std::vector<PropertyObject*> protectedPropertyObjects;
		std::vector<PropertyObject*> privatePropertyObjects;

		std::vector<BaseTypeObject*> baseTypes;

		StructObject(const std::string& type_ = "");
		~StructObject() override = default;

		// Using a flavor this can be set to any default
		void AddFunction(FunctionObject* functionObject,
						 AccessModifier modifier = AccessModifier::Public);

		void AddProperty(PropertyObject* propertyObject,
						 AccessModifier modifier = AccessModifier::Public);

		void AddBaseType(BaseTypeObject* baseType);
		
		void Print() override;

		std::vector<FunctionObject*> GetPublicFunctions() const;
		std::vector<FunctionObject*> GetProtectedFunctions() const;
		std::vector<FunctionObject*> GetPrivateFunctions() const;

		std::vector<PropertyObject*> GetPrivateProperties() const;
		std::vector<PropertyObject*> GetProtectedProperties() const;
		std::vector<PropertyObject*> GetPublicProperties() const;

		std::vector<BaseTypeObject*> GetBaseTypes() const;
		
	};
}

#endif // DEAMER_EXTERNAL_CPP_TOOL_OOPSYNTAXRECOGNIZER_TYPE_STRUCTOBJECT_H
