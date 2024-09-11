if (distance <= 100.00f && settings::visuals::Indicators) {
				float circleRadius = combat::fov * 10;
				float fCompassSize = circleRadius + 10;

				float cCenterX = ue5::width / 2.0f;
				float cCenterY = ue5::height / 2.0f;

				float dx = m_camera_information.Location.X - head_bone_pos.X;
				float dy = m_camera_information.Location.Y - head_bone_pos.Y;

				float Angle = m_camera_information.Rotation.Y / 180 * M_PI;
				float RotateX = -(dy * cosf(Angle) - dx * sinf(Angle));
				float RotateY = (dx * cosf(Angle) + dy * sinf(Angle));

				float angle = atan(RotateX / RotateY) * (180 / M_PI);
				float FinalA = (cCenterY + RotateY / 125.f) > cCenterY ? -angle - 180.0f : -angle;
				if (FinalA < 0) FinalA += 360.0f;

				float radians = (M_PI / 180) * (FinalA - 90.0f);
				float radians1 = (M_PI / 180) * (FinalA - 90.0f + 2.f);
				float radians2 = (M_PI / 180) * (FinalA - 90.0f - 2.f);

				float widthFactor = 0.200f;

				float CircleOutX = cCenterX + (cosf(radians) * (fCompassSize + (fCompassSize / 5.f) * widthFactor));
				float CircleOutY = cCenterY + (sinf(radians) * (fCompassSize + (fCompassSize / 5.f) * widthFactor));
				float CircleOut1X = cCenterX + (cosf(radians1) * (fCompassSize - (fCompassSize / 7.5f) * widthFactor));
				float CircleOut1Y = cCenterY + (sinf(radians1) * (fCompassSize - (fCompassSize / 7.5f) * widthFactor));
				float CircleOut2X = cCenterX + (cosf(radians2) * (fCompassSize - (fCompassSize / 7.5f) * widthFactor));
				float CircleOut2Y = cCenterY + (sinf(radians2) * (fCompassSize - (fCompassSize / 7.5f) * widthFactor));

				ImVec2 vertices[3] = { ImVec2(CircleOutX, CircleOutY), ImVec2(CircleOut1X, CircleOut1Y), ImVec2(CircleOut2X, CircleOut2Y) };

				ImGui::GetForegroundDrawList()->AddTriangleFilled(vertices[0], vertices[1], vertices[2], c_color);
}
