#ifndef _RTEVECTOR_
#define _RTEVECTOR_

#include "Serializable.h"
#include "RTETools.h"

namespace RTE {

	enum Axes { X = 0, Y = 1 };

	/// <summary>
	/// A useful 2D float vector.
	/// </summary>
	class Vector : public Serializable {

	public:

		SerializableOverrideMethods

		float m_X = 0.0F; //!< X value of this vector.
		float m_Y = 0.0F; //!< Y value of this vector.

#pragma region Creation
		/// <summary>
		/// Constructor method used to instantiate a Vector object with values (0, 0).
		/// </summary>
		Vector() {};

		/// <summary>
		/// Constructor method used to instantiate a Vector object from X and Y values.
		/// </summary>
		/// <param name="inputX">Float defining the initial X value of this Vector.</param>
		/// <param name="inputY">Float defining the initial Y value of this Vector.</param>
		Vector(const float inputX, const float inputY) :
			m_X(inputX),
			m_Y(inputY) {};

		/// <summary>
		/// Copy constructor method used to instantiate a Vector object identical to an already existing one.
		/// </summary>
		/// <param name="reference">A Vector object which is passed in by reference.</param>
		Vector(const Vector &reference) = default;
#pragma endregion

#pragma region Getters and Setters
		/// <summary>
		/// Sets both the X and Y of this Vector to zero.
		/// </summary>
		void Reset() { m_X = 0.0F; m_Y = 0.0F; }

		/// <summary>
		/// Gets the X value of this Vector.
		/// </summary>
		/// <returns>A float value that represents the X value of this Vector.</returns>
		float GetX() const { return m_X; }

		/// <summary>
		/// Sets the X value of this Vector.
		/// </summary>
		/// <param name="newX">A float value that the X value will be set to.</param>
		void SetX(const float newX) { m_X = newX; }

		/// <summary>
		/// Sets the X value of this Vector.
		/// </summary>
		/// <param name="newX">An int value that the X value will be set to.</param>
		void SetIntX(const int newX) { m_X = static_cast<float>(newX); }

		/// <summary>
		/// Gets the Y value of this Vector.
		/// </summary>
		/// <returns>A float value that represents the Y value of this Vector.</returns>
		float GetY() const { return m_Y; }

		/// <summary>
		/// Sets the Y value of this Vector.
		/// </summary>
		/// <param name="newY">A float value that the Y value will be set to.</param>
		void SetY(const float newY) { m_Y = newY; }

		/// <summary>
		/// Sets the Y value of this Vector.
		/// </summary>
		/// <param name="newY">An int value that the Y value will be set to.</param>
		void SetIntY(const int newY) { m_Y = static_cast<float>(newY); }

		/// <summary>
		/// Sets both the X and Y values of this Vector.
		/// </summary>
		/// <param name="newX">A float value that the X value will be set to.</param>
		/// <param name="newY">A float value that the Y value will be set to.</param>
		void SetXY(const float newX, const float newY) { m_X = newX; m_Y = newY; }

		/// <summary>
		/// Sets both the X and Y values of this Vector.
		/// </summary>
		/// <param name="newX">An int value that the X value will be set to.</param>
		/// <param name="newY">An int value that the Y value will be set to.</param>
		void SetIntXY(const int newX, const int newY) { m_X = static_cast<float>(newX); m_Y = static_cast<float>(newY); }

		/// <summary>
		/// Gets the absolute largest of the two elements. Will always be positive.
		/// </summary>
		/// <returns>A float describing the largest value of the two, but not the magnitude.</returns>
		float GetLargest() const { return std::max(std::abs(m_X), std::abs(m_Y)); }

		/// <summary>
		/// Gets the absolute smallest of the two elements. Will always be positive.
		/// </summary>
		/// <returns>A float describing the smallest value of the two, but not the magnitude.</returns>
		float GetSmallest() const { return std::min(std::abs(m_X), std::abs(m_Y)); }

		/// <summary>
		/// Gets a Vector identical to this except that its X component is flipped.
		/// </summary>
		/// <param name="xFlip">Whether to flip the X axis of the return vector or not.</param>
		/// <returns>A copy of this vector with flipped X axis.</returns>
		Vector GetXFlipped(const bool xFlip = true) const { return Vector(xFlip ? -m_X : m_X, m_Y); }

		/// <summary>
		/// Flips the X element of this Vector.
		/// </summary>
		/// <param name="flipX">Whether or not to flip the X element or not.</param>
		void FlipX(const bool flipX = true) { *this = GetYFlipped(flipX); }

		/// <summary>
		/// Gets a Vector identical to this except that its Y component is flipped.
		/// </summary>
		/// <param name="yFlip">Whether to flip the Y axis of the return vector or not.</param>
		/// <returns>A copy of this vector with flipped Y axis.</returns>
		Vector GetYFlipped(const bool yFlip = true) const { return Vector(m_X, yFlip ? -m_Y : m_Y); }

		/// <summary>
		/// Flips the Y element of this Vector.
		/// </summary>
		/// <param name="flipY">Whether or not to flip the Y element or not.</param>
		void FlipY(const bool flipY = true) { *this = GetYFlipped(flipY); }

		/// <summary>
		/// Indicates whether the X component of this Vector is 0.
		/// </summary>
		/// <returns>Whether the X component of this Vector is 0.</returns>
		bool XIsZero() const { return m_X == 0; }

		/// <summary>
		/// Indicates whether the Y component of this Vector is 0.
		/// </summary>
		/// <returns>Whether the Y component of this Vector is 0.</returns>
		bool YIsZero() const { return m_Y == 0; }

		/// <summary>
		/// Indicates whether both X and Y components of this Vector are 0.
		/// </summary>
		/// <returns>Whether both X and Y components of this Vector are 0.</returns>
		bool IsZero() const { return XIsZero() && YIsZero(); }

		/// <summary>
		/// Indicates whether the X and Y components of this Vector each have opposite signs to their corresponding components of a passed in Vector.
		/// </summary>
		/// <param name="opp">The Vector to compare with.</param>
		/// <returns>Whether the X and Y components of this Vector each have opposite signs to their corresponding components of a passed in Vector.</returns>
		bool IsOpposedTo(const Vector &opp) const { return ((XIsZero() && opp.XIsZero()) || (std::signbit(m_X) != std::signbit(opp.m_X))) && ((YIsZero() && opp.YIsZero()) || (std::signbit(m_Y) != std::signbit(opp.m_Y))); }
#pragma endregion

#pragma region Magnitude
		/// <summary>
		/// Gets the magnitude of this Vector.
		/// </summary>
		/// <returns>A float describing the magnitude.</returns>
		float GetMagnitude() const { return std::sqrt(std::pow(m_X, 2.0F) + std::pow(m_Y, 2.0F)); }

		/// <summary>
		/// Sets the magnitude of this Vector. A negative magnitude will invert the Vector's direction.
		/// </summary>
		/// <param name="newMag">A float value that the magnitude will be set to.</param>
		/// <returns>A reference to this after the change.</returns>
		Vector & SetMagnitude(const float newMag);

		/// <summary>
		/// Caps the magnitude of this Vector to a max value and keeps its angle intact.
		/// </summary>
		/// <param name="capMag">A float value that the magnitude will be capped by.</param>
		/// <returns>A reference to this after the change.</returns>
		Vector & CapMagnitude(const float capMag);

		/// <summary>
		/// Returns a Vector that has the same direction as this but with a magnitude of 1.0.
		/// </summary>
		/// <returns>A normalized copy of this vector.</returns>
		Vector GetNormalized() const { return *this / GetMagnitude(); }

		/// <summary>
		/// Scales this vector to have the same direction but a magnitude of 1.0.
		/// </summary>
		/// <returns>Vector reference to this after the operation.</returns>
		Vector & Normalize() { *this = GetNormalized(); return *this; }
#pragma endregion

#pragma region Rotation
		/// <summary>
		/// Get this Vector's absolute angle in radians. e.g: when x = 1, y = 0, the value returned here will be 0. x = 0, y = 1 yields -pi/2 here.
		/// </summary>
		/// <returns>The absolute angle in radians, in the interval [-0.5 pi, 1.5 pi).</returns>
		float GetAbsRadAngle() const;

		/// <summary>
		/// Get this Vector's absolute angle in degrees. e.g: when x = 1, y = 0, the value returned here will be 0. x = 0, y = 1 yields -90 here.
		/// </summary>
		/// <returns>The absolute angle in degrees, in the interval [-90, 270).</returns>
		float GetAbsDegAngle() const { return GetAbsRadAngle() / c_PI * 180.0F; }

		/// <summary>
		/// Rotate this Vector relatively by an angle in radians.
		/// </summary>
		/// <param name="angle">The angle in radians to rotate by. Positive angles rotate counter-clockwise, and negative angles clockwise.</param>
		/// <returns>This vector, rotated.</returns>
		Vector & RadRotate(const float angle);

		/// <summary>
		/// Rotate this Vector relatively by an angle in degrees.
		/// </summary>
		/// <param name="angle">The angle in degrees to rotate by. Positive angles rotate counter-clockwise, and negative angles clockwise.</param>
		/// <returns>This vector, rotated.</returns>
		Vector & DegRotate(const float angle) { return RadRotate(angle * c_PI / 180.0F); }

		/// <summary>
		/// Set this Vector to an absolute rotation based on the absolute rotation of another Vector.
		/// </summary>
		/// <param name="refVector">The reference Vector whose absolute angle from positive X (0 degrees) this Vector will be rotated to.</param>
		/// <returns>This vector, rotated.</returns>
		Vector & AbsRotateTo(const Vector &refVector) { return RadRotate(refVector.GetAbsRadAngle() - GetAbsRadAngle()); }

		/// <summary>
		/// Returns a Vector that is perpendicular to this, rotated PI/2.
		/// </summary>
		/// <returns>A Vector that is perpendicular to this, rotated PI/2.</returns>
		Vector GetPerpendicular() const { return Vector(m_Y, -m_X); }

		/// <summary>
		/// Makes this vector perpendicular to its previous state, rotated PI/2. Much faster than RadRotate by PI/2.
		/// </summary>
		/// <returns>Vector reference to this after the operation.</returns>
		Vector & Perpendicularize() { *this = GetPerpendicular(); return *this; }
#pragma endregion

#pragma region Rounding
		/// <summary>
		/// Rounds the X and Y values of this Vector upwards. E.g. 0.49 -> 0.0 and 0.5 -> 1.0.
		/// </summary>
		void Round() { *this = GetRounded(); }

		/// <summary>
		/// Sets the X and Y of this Vector to the nearest half value. E.g. 1.0 -> 1.5 and 0.9 -> 0.5.
		/// </summary>
		void ToHalf() { m_X = std::round(m_X * 2) / 2; m_Y = std::round(m_Y * 2) / 2; }

		/// <summary>
		/// Sets the X and Y of this Vector to the greatest integers that are not greater than their original values. E.g. -1.02 becomes -2.0.
		/// </summary>
		void Floor() { *this = GetFloored(); }

		/// <summary>
		/// Sets the X and Y of this Vector to the lowest integers that are not less than their original values. E.g. -1.02 becomes -1.0.
		/// </summary>
		void Ceiling() { *this = GetCeilinged(); }

		/// <summary>
		/// Returns a rounded copy of this Vector. Does not alter this Vector.
		/// </summary>
		/// <returns>A rounded copy of this Vector.</returns>
		Vector GetRounded() const { return Vector(std::round(m_X), std::round(m_Y)); }

		/// <summary>
		/// Returns the rounded integer X value of this Vector.
		/// </summary>
		/// <returns>An int value that represents the X value of this Vector.</returns>
		int GetRoundIntX() const { return static_cast<int>(std::round(m_X)); }

		/// <summary>
		/// Returns the rounded integer Y value of this Vector.
		/// </summary>
		/// <returns>An int value that represents the Y value of this Vector.</returns>
		int GetRoundIntY() const { return static_cast<int>(std::round(m_Y)); }

		/// <summary>
		/// Returns a floored copy of this Vector. Does not alter this Vector.
		/// </summary>
		/// <returns>A floored copy of this Vector.</returns>
		Vector GetFloored() const { return Vector(std::floor(m_X), std::floor(m_Y)); }

		/// <summary>
		/// Returns the greatest integer that is not greater than the X value of this Vector.
		/// </summary>
		/// <returns>An int value that represents the X value of this Vector.</returns>
		int GetFloorIntX() const { return static_cast<int>(std::floor(m_X)); }

		/// <summary>
		/// Returns the greatest integer that is not greater than the Y value of this Vector.
		/// </summary>
		/// <returns>An int value that represents the Y value of this Vector.</returns>
		int GetFloorIntY() const { return static_cast<int>(std::floor(m_Y)); }

		/// <summary>
		/// Returns a ceilinged copy of this Vector. Does not alter this Vector.
		/// </summary>
		/// <returns>A ceilinged copy of this Vector.</returns>
		Vector GetCeilinged() const { return Vector(std::ceil(m_X), std::ceil(m_Y)); }

		/// <summary>
		/// Returns the lowest integer that is not less than the X value of this Vector.
		/// </summary>
		/// <returns>An int value that represents the X value of this Vector.</returns>
		int GetCeilingIntX() const { return static_cast<int>(std::ceil(m_X)); }

		/// <summary>
		/// Returns the lowest integer that is not less than the Y value of this Vector.
		/// </summary>
		/// <returns>An int value that represents the Y value of this Vector.</returns>
		int GetCeilingIntY() const { return static_cast<int>(std::ceil(m_Y)); }
#pragma endregion

#pragma region Vector Products
		/// <summary>
		/// Returns the dot product of this Vector and the passed in Vector.
		/// </summary>
		/// <param name="rhs">The Vector which will be the right hand side operand of the dot product operation.</param>
		/// <returns>The resulting dot product scalar float.</returns>
		float Dot(const Vector &rhs) const { return (m_X * rhs.m_X) + (m_Y * rhs.m_Y); }

		/// <summary>
		/// Returns the 2D cross product of this Vector and the passed in Vector. This is really the area of the parallelogram that the two vectors form.
		/// </summary>
		/// <param name="rhs">The Vector which will be the right hand side operand of the cross product operation.</param>
		/// <returns>The resulting 2D cross product parallelogram area.</returns>
		float Cross(const Vector &rhs) const { return (m_X * rhs.m_Y) - (rhs.m_X * m_Y); }
#pragma endregion

#pragma region Operator Overloads
		/// <summary>
		/// Copy assignment operator for Vectors.
		/// </summary>
		/// <param name="rhs">A Vector reference.</param>
		/// <returns>A reference to the changed Vector.</returns>
		Vector & operator=(const Vector &rhs) = default;

		/// <summary>
		/// An assignment operator for setting this Vector equal to the average of an std::deque of Vectors.
		/// </summary>
		/// <param name="rhs">A reference to an std::deque of Vectors that shall be averaged.</param>
		/// <returns>A reference to the changed Vector (this).</returns>
		Vector & operator=(const std::deque<Vector> &rhs);

		/// <summary>
		/// Unary negation overload for single Vectors.
		/// </summary>
		/// <returns>The resulting Vector.</returns>
		Vector operator-() { return Vector(-m_X, -m_Y); }

		/// <summary>
		/// An equality operator for testing if any two Vectors are equal.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>A boolean indicating whether the two operands are equal or not.</returns>
		friend bool operator==(const Vector &lhs, const Vector &rhs) { return lhs.m_X == rhs.m_X && lhs.m_Y == rhs.m_Y; }

		/// <summary>
		/// An inequality operator for testing if any two Vectors are unequal.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>A boolean indicating whether the two operands are unequal or not.</returns>
		friend bool operator!=(const Vector &lhs, const Vector &rhs) { return !(lhs == rhs); }

		/// <summary>
		/// A stream insertion operator for sending a Vector to an output stream.
		/// </summary>
		/// <param name="stream">An ostream reference as the left hand side operand.</param>
		/// <param name="operand">A Vector reference as the right hand side operand.</param>
		/// <returns>An ostream reference for further use in an expression.</returns>
		friend std::ostream & operator<<(std::ostream &stream, const Vector &operand) { stream << "{" << operand.m_X << ", " << operand.m_Y << "}"; return stream; }

		/// <summary>
		/// Addition operator overload for Vectors.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>The resulting Vector.</returns>
		friend Vector operator+(const Vector &lhs, const Vector &rhs) { return Vector(lhs.m_X + rhs.m_X, lhs.m_Y + rhs.m_Y); }

		/// <summary>
		/// Subtraction operator overload for Vectors.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>The resulting Vector.</returns>
		friend Vector operator-(const Vector &lhs, const Vector &rhs) { return Vector(lhs.m_X - rhs.m_X, lhs.m_Y - rhs.m_Y); }

		/// <summary>
		/// Multiplication operator overload for a Vector and a float.
		/// </summary>
		/// <param name="rhs">A float reference as the right hand side operand.</param>
		/// <returns>The resulting Vector.</returns>
		Vector operator*(const float &rhs) const { return Vector(m_X * rhs, m_Y * rhs); }

		/// <summary>
		/// Multiplication operator overload for Vectors.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>The resulting Vector.</returns>
		friend Vector operator*(const Vector &lhs, const Vector &rhs) { return Vector(lhs.m_X * rhs.m_X, lhs.m_Y * rhs.m_Y); }

		/// <summary>
		/// Division operator overload for a Vector and a float.
		/// </summary>
		/// <param name="rhs">A float reference as the right hand side operand.</param>
		/// <returns>The resulting Vector.</returns>
		Vector operator/(const float &rhs) const {
			Vector returnVector(0, 0);
			if (rhs != 0) { returnVector.SetXY(m_X / rhs, m_Y / rhs); }
			return returnVector;
		}

		/// <summary>
		/// Division operator overload for Vectors.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>The resulting Vector.</returns>
		friend Vector operator/(const Vector &lhs, const Vector &rhs) {
			Vector returnVector(0, 0);
			if (rhs.m_X != 0 && rhs.m_Y != 0) { returnVector.SetXY(lhs.m_X / rhs.m_X, lhs.m_Y / rhs.m_Y); }
			return returnVector;
		}

		/// <summary>
		/// Self-addition operator overload for Vectors.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>A reference to the resulting Vector (the left one).</returns>
		friend Vector & operator+=(Vector &lhs, const Vector &rhs) { lhs.m_X += rhs.m_X; lhs.m_Y += rhs.m_Y; return lhs; }

		/// <summary>
		/// Self-subtraction operator overload for Vectors.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>A reference to the resulting Vector (the left one).</returns>
		friend Vector & operator-=(Vector &lhs, const Vector &rhs) { lhs.m_X -= rhs.m_X; lhs.m_Y -= rhs.m_Y; return lhs; }

		/// <summary>
		/// Self-multiplication operator overload for a Vector and a float.
		/// </summary>
		/// <param name="rhs">A float reference as the right hand side operand.</param>
		/// <returns>A reference to the resulting Vector.</returns>
		Vector & operator*=(const float &rhs) { m_X *= rhs; m_Y *= rhs; return *this; }

		/// <summary>
		/// Self-multiplication operator overload for Vectors.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>A reference to the resulting Vector (the left one).</returns>
		friend Vector & operator*=(Vector &lhs, const Vector &rhs) { lhs.m_X *= rhs.m_X; lhs.m_Y *= rhs.m_Y; return lhs; }

		/// <summary>
		/// self-division operator overload for a Vector and a float.
		/// </summary>
		/// <param name="rhs">A float reference as the right hand side operand.</param>
		/// <returns>A reference to the resulting Vector.</returns>
		Vector & operator/=(const float &rhs) { if (rhs != 0) { m_X /= rhs; m_Y /= rhs; } return *this; }

		/// <summary>
		/// Self-division operator overload for Vectors.
		/// </summary>
		/// <param name="lhs">A Vector reference as the left hand side operand.</param>
		/// <param name="rhs">A Vector reference as the right hand side operand.</param>
		/// <returns>A reference to the resulting Vector (the left one).</returns>
		friend Vector & operator/=(Vector &lhs, const Vector &rhs) {
			if (rhs.m_X != 0) { lhs.m_X /= rhs.m_X; }
			if (rhs.m_Y != 0) { lhs.m_Y /= rhs.m_Y; }
			return lhs;
		}

		/// <summary>
		/// Array subscripting to access either the X or Y element of this Vector.
		/// </summary>
		/// <param name="rhs">An int index indicating which element is requested (X = 0, Y = 1).</param>
		/// <returns>The requested element.</returns>
		const float & operator[](const int &rhs) const { return (rhs == 0) ? m_X : m_Y; }

		/// <summary>
		/// Array subscripting to access either the X or Y element of this Vector.
		/// </summary>
		/// <param name="rhs">An int index indicating which element is requested (X = 0, Y = 1).</param>
		/// <returns>The requested element.</returns>
		float & operator[](const int &rhs) { return (rhs == 0) ? m_X : m_Y; }
#pragma endregion

#pragma region Class Info
		/// <summary>
		/// Gets the class name of this Vector.
		/// </summary>
		/// <returns>A string with the friendly-formatted type name of this Vector.</returns>
		const std::string & GetClassName() const override { return c_ClassName; }
#pragma endregion

	private:

		static const std::string c_ClassName; //!< A string with the friendly-formatted type name of this.
	};
}
#endif
