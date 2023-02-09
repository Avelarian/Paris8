import { hashSync, compareSync } from 'bcrypt';

export function hashPassword(password: string): string {
  return hashSync(password, 10);
}

export function comparePassword(password: string, hash: string): boolean {
  return compareSync(password, hash);
}

export function removeSpecialCharactersAndSpaces(value: string): string {
  return value.replace(/[^a-zA-Z0-9]/g, '');
}
