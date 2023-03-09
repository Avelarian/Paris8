import { IsString, Matches, MaxLength, MinLength } from 'class-validator';

export class AuthDto {
  @IsString()
  @MinLength(4)
  @MaxLength(20)
  username: string;

  @IsString()
  @MinLength(4)
  @MaxLength(20)
  @Matches(/((?=.*\d)|(?=.*\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$/, {
    message:
      'Password is too weak. It must have at least 4 characters, and at max 20.',
  })
  password: string;

  @IsString()
  @MinLength(4)
  @MaxLength(20)
  @Matches('password')
  passwordConfirm: string;
}
