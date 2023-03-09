import {
  BadRequestException,
  Injectable,
  NotImplementedException,
} from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import {
  comparePassword,
  hashPassword,
  removeSpecialCharactersAndSpaces,
} from 'src/shared/utils';
import { AuthDto } from './dto/auth.dto';
import { JwtService } from '@nestjs/jwt';

@Injectable()
export class AuthService {
  constructor(
    private readonly prisma: PrismaService,
    private readonly jwtService: JwtService,
  ) {}

  async register(registerDto: AuthDto) {
    const { username, password } = registerDto;

    if (username === undefined || username === null || username === '') {
      throw new BadRequestException(`Username is required`);
    }

    if (password === undefined || password === null || password === '') {
      throw new BadRequestException(`Password is required`);
    }

    const preparedUsername = removeSpecialCharactersAndSpaces(username);

    const allUsernames = await this.prisma.user
      .findMany({
        select: { username: true },
      })
      .then((users) => users.map((user) => user.username));

    if (allUsernames.includes(preparedUsername)) {
      throw new BadRequestException(`Username already exists`);
    }

    const hashedPassword = hashPassword(password);

    const user = await this.prisma.user
      .create({
        data: { username: preparedUsername, password: hashedPassword },
        select: { username: true },
      })
      .catch((error) => {
        console.log(error);
        throw new NotImplementedException(
          `Oups... Please, retry in a few minutes.`,
        );
      });

    return user;
  }

  async login(loginDto: AuthDto) {
    const { username, password } = loginDto;

    if (username === undefined || username === null || username === '') {
      throw new BadRequestException(`Username is required`);
    }

    if (password === undefined || password === null || password === '') {
      throw new BadRequestException(`Password is required`);
    }

    const preparedUsername = removeSpecialCharactersAndSpaces(username);

    const allUsers = await this.prisma.user.findMany();

    const allUsernames = allUsers.map((user) => user.username);

    if (!allUsernames.includes(preparedUsername)) {
      throw new BadRequestException(`Username does not exist`);
    }

    const user = allUsers.find((user) => user.username === preparedUsername);

    if (comparePassword(password, user.password)) {
      return {
        access_token: this.jwtService.sign({ preparedUsername }),
      };
    }

    throw new BadRequestException(`Password is incorrect`);
  }
}
