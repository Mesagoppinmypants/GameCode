/*
 *	FBCampSite.cpp generated by engine3 IDL compiler 0.55
 */

#include "FBCampSite.h"

#include "FBCampSiteImplementation.h"

#include "../campsite/CampSite.h"

#include "../CampKit.h"

#include "../../../player/Player.h"

/*
 *	FBCampSiteStub
 */

FBCampSite::FBCampSite(Player* player, unsigned long long oid, CampKit* campKit) : CampSite(DummyConstructorParameter::instance()) {
	_impl = new FBCampSiteImplementation(player, oid, campKit);
	_impl->_setStub(this);
}

FBCampSite::FBCampSite(DummyConstructorParameter* param) : CampSite(param) {
}

FBCampSite::~FBCampSite() {
}

void FBCampSite::spawnCampItems() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((FBCampSiteImplementation*) _impl)->spawnCampItems();
}

/*
 *	FBCampSiteAdapter
 */

FBCampSiteAdapter::FBCampSiteAdapter(FBCampSiteImplementation* obj) : CampSiteAdapter(obj) {
}

Packet* FBCampSiteAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		spawnCampItems();
		break;
	default:
		return NULL;
	}

	return resp;
}

void FBCampSiteAdapter::spawnCampItems() {
	return ((FBCampSiteImplementation*) impl)->spawnCampItems();
}

/*
 *	FBCampSiteHelper
 */

FBCampSiteHelper* FBCampSiteHelper::staticInitializer = FBCampSiteHelper::instance();

FBCampSiteHelper::FBCampSiteHelper() {
	className = "FBCampSite";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void FBCampSiteHelper::finalizeHelper() {
	FBCampSiteHelper::finalize();
}

DistributedObject* FBCampSiteHelper::instantiateObject() {
	return new FBCampSite(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FBCampSiteHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FBCampSiteAdapter((FBCampSiteImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	FBCampSiteServant
 */

FBCampSiteServant::FBCampSiteServant(Player* player, unsigned long long oid, CampKit* campKit) : CampSiteImplementation(player, oid, campKit) {
	_classHelper = FBCampSiteHelper::instance();
}

FBCampSiteServant::~FBCampSiteServant() {
}

void FBCampSiteServant::_setStub(DistributedObjectStub* stub) {
	_this = (FBCampSite*) stub;
	CampSiteServant::_setStub(stub);
}

DistributedObjectStub* FBCampSiteServant::_getStub() {
	return _this;
}

