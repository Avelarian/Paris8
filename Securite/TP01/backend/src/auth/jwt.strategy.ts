import { ExtractJwt, Strategy } from 'passport-jwt';
import { PassportStrategy } from '@nestjs/passport';
import { Injectable } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';

@Injectable()
export class JwtStrategy extends PassportStrategy(Strategy) {
  constructor(private readonly prisma: PrismaService) {
    super({
      jwtFromRequest: ExtractJwt.fromAuthHeaderAsBearerToken(),
      ignoreExpiration: false,
      secretOrKey: process.env.JWT_SECRET,
    });
  }

  async validate(payload: { preparedUsername: string }) {
    const allUsernames = await this.prisma.user
      .findMany({ select: { username: true } })
      .then((users) => users.map((user) => user.username));

    if (!allUsernames.includes(payload.preparedUsername)) {
      throw new Error('User not found');
    }

    return { username: payload.preparedUsername };
  }
}
