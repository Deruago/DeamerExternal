#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/InterfaceObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/BaseTypeObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionArgument.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/FunctionObject.h"
#include "Deamer/External/Cpp/Tool/OopSyntaxRecognizer/Type/PropertyObject.h"
#include <iostream>

deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::InterfaceObject(
	const std::string& type_)
	: Type(TypeCategory::interfaceobject, type_)
{
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::AddFunction(
	FunctionObject* functionObject, AccessModifier modifier)
{
	switch (modifier)
	{
	case AccessModifier::Public: {
		publicFunctionObjects.push_back(functionObject);
		break;
	}
	case AccessModifier::Protected: {
		protectedFunctionObjects.push_back(functionObject);
		break;
	}
	case AccessModifier::Private: {
		privateFunctionObjects.push_back(functionObject);
		break;
	}
	}
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::AddProperty(
	PropertyObject* propertyObject, AccessModifier modifier)
{
	switch (modifier)
	{
	case AccessModifier::Public: {
		publicPropertyObjects.push_back(propertyObject);
		break;
	}
	case AccessModifier::Protected: {
		protectedPropertyObjects.push_back(propertyObject);
		break;
	}
	case AccessModifier::Private: {
		privatePropertyObjects.push_back(propertyObject);
		break;
	}
	}
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::AddBaseType(
	BaseTypeObject* baseType)
{
	baseTypes.push_back(baseType);
}

void deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::Print()
{
	std::cout << "STRUCT: " << GetTypeName() << "\n";

	auto functionPrinter = [](std::vector<FunctionObject*>& functionObjects) {
		for (const auto& functionObject : functionObjects)
		{
			if (functionObject == nullptr)
			{
				throw std::logic_error("InterfaceObject.Print: FunctionObject is nullptr.");
			}
			if (functionObject->GetReturnType() == nullptr)
			{
				throw std::logic_error(
					"InterfaceObject.Print: FunctionObject.GetReturnType() is nullptr.");
			}

			std::cout << "\t\tFUNCTION: " << functionObject->GetName()
					  << " ReturnType: " << functionObject->GetReturnType()->GetTypeName()
					  << " Args: ";
			for (const auto& functionArgument : functionObject->GetFunctionArguments())
			{
				std::cout << functionArgument->GetName() << " "
						  << functionArgument->GetType()->GetTypeName();
				std::cout << ", ";
			}
			std::cout << "\n";
		}
	};

	auto propertyPrinter = [](std::vector<PropertyObject*>& propertyObjects) {
		for (const auto& propertyObject : propertyObjects)
		{
			if (propertyObject == nullptr)
			{
				throw std::logic_error("InterfaceObject.Print: PropertyObject is nullptr.");
			}
			if (propertyObject->GetType() == nullptr)
			{
				throw std::logic_error(
					"InterfaceObject.Print: PropertyObject->GetType() is nullptr.");
			}
			std::cout << "\t\tPROPERTY: " << propertyObject->GetName()
					  << " Type: " << propertyObject->GetType()->GetTypeName() << "\n";
		}
	};

	std::cout << "\tPublic Functions: \n";
	functionPrinter(publicFunctionObjects);

	std::cout << "\tProtected Functions: \n";
	functionPrinter(protectedFunctionObjects);

	std::cout << "\tPrivate Functions: \n";
	functionPrinter(privateFunctionObjects);

	std::cout << "\tPublic Property: \n";
	propertyPrinter(publicPropertyObjects);

	std::cout << "\tProtected Property: \n";
	propertyPrinter(protectedPropertyObjects);

	std::cout << "\tPrivate Property: \n";
	propertyPrinter(privatePropertyObjects);
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::GetPublicFunctions() const
{
	return publicFunctionObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::GetProtectedFunctions() const
{
	return protectedFunctionObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::FunctionObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::GetPrivateFunctions() const
{
	return privateFunctionObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::GetPrivateProperties() const
{
	return privatePropertyObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::GetProtectedProperties() const
{
	return protectedPropertyObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::PropertyObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::GetPublicProperties() const
{
	return publicPropertyObjects;
}

std::vector<deamer::external::cpp::tool::oopsyntaxrecognizer::BaseTypeObject*>
deamer::external::cpp::tool::oopsyntaxrecognizer::InterfaceObject::GetBaseTypes() const
{
	return baseTypes;
}
