#include "rope_appearance.h"

void RopeAppearance::_bind_methods() {
	// rope parameters
	EXPORT_PROPERTY(Variant::FLOAT, rope_width, RopeAppearance);
	EXPORT_PROPERTY(Variant::INT, rope_sides, RopeAppearance);
	EXPORT_PROPERTY(Variant::FLOAT, rope_twist, RopeAppearance);
	EXPORT_PROPERTY(Variant::INT, rope_lod, RopeAppearance);
	EXPORT_PROPERTY(Variant::INT, particles_per_meter, RopeAppearance);

	ClassDB::bind_method(D_METHOD("set_material", "material"), &RopeAppearance::set_material);
	ClassDB::bind_method(D_METHOD("get_material"), &RopeAppearance::get_material);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "material", PROPERTY_HINT_RESOURCE_TYPE, "Material"), "set_material", "get_material");

	ClassDB::bind_method(D_METHOD("set_link_mesh", "array_mesh"), &RopeAppearance::set_array_mesh);
	ClassDB::bind_method(D_METHOD("get_link_mesh"), &RopeAppearance::get_array_mesh);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "link_mesh", PROPERTY_HINT_RESOURCE_TYPE, "ArrayMesh"), "set_link_mesh", "get_link_mesh");

	// attachments
	EXPORT_PROPERTY(Variant::NODE_PATH, start_attachment, RopeAppearance);
	EXPORT_PROPERTY(Variant::FLOAT, start_offset, RopeAppearance);
	EXPORT_PROPERTY(Variant::NODE_PATH, end_attachment, RopeAppearance);
	EXPORT_PROPERTY(Variant::FLOAT, end_offset, RopeAppearance);
	ClassDB::bind_method(D_METHOD("set_attachments", "attachments"), &RopeAppearance::set_attachments);
	ClassDB::bind_method(D_METHOD("get_attachments"), &RopeAppearance::get_attachments);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "attachments", PROPERTY_HINT_RESOURCE_TYPE, "RopePositions"), "set_attachments", "get_attachments");
}

void RopeAppearance::set_material(const Ref<Material> &p_material) {
	_material = p_material;
	_notify_change();
}

Ref<Material> RopeAppearance::get_material() const {
	return _material;
}

void RopeAppearance::set_array_mesh(const Ref<ArrayMesh> &p_mesh) {
	_mesh = p_mesh;
	_notify_change();
}

Ref<ArrayMesh> RopeAppearance::get_array_mesh() const {
	return _mesh;
}

#pragma endregion